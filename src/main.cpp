#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

#include <iostream>
#include <filesystem>

#include <random>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#include <filesystem>
#endif

#include "shaders/VertexShader.h"
#include "shaders/FragmentShader.h"
#include "shaders/ShaderProgram.h"

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

#include "Object.h"
#include "Sprite.h"
#include "Polygon.h"
#include "Texture.h"

#include "vector.h"

// input system
#include "Input.h"
Input input;

#include "Player.h"


// queued actions from key presses that should be handled in the render loop
std::vector<std::string> actionQueue;

// actions ignored by the key callback because they are handled directly in processInput
std::vector<std::string> actionQueueIgnore = 
{
    "up",
    "down",
    "left",
    "right",
    "dodge",
  //  "menu",
    "pause"
};

// callback registration happens in main()


//OBJECT STUFF
std::vector<Object> objectList;

#ifdef _WIN32
static std::filesystem::path getExecutablePath()
{

    char exePath[MAX_PATH];
    DWORD length = GetModuleFileNameA(NULL, exePath, MAX_PATH);
    if (length > 0 && length < MAX_PATH)
    {
        return std::filesystem::path(exePath);
    }

    return std::filesystem::current_path();
}
#endif

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
bool keyIsPressed(int key, GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

vec3 teto_transform;

// helper returns whether the given GLFW key is currently pressed
bool keyIsPressed(int key, GLFWwindow* window){
    return glfwGetKey(window, key) == GLFW_PRESS;
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// Movement keys are handled immediately, while queued actions are deferred into the render loop.
void processInput(GLFWwindow *window, float deltaTime, vec3& transform, Player *player = nullptr)
{
    // Let ImGui consume keyboard input while interacting with a UI control.
    if (ImGui::GetIO().WantCaptureKeyboard) {
        return;
    }

    if (keyIsPressed(input.translateToKeyID("pause"), window)){
        glfwSetWindowShouldClose(window, true);
    }
    // if (keyIsPressed(input.translateToKeyID("menu"), window))
    // {
    //     //menu() or inv() or smth
    // }

    if (keyIsPressed(input.translateToKeyID("up"), window)){
        transform += vec3(0.0f, 0.5f, 0.0f);
    }
    if (keyIsPressed(input.translateToKeyID("down"), window)){
        transform += vec3(0.0f, -0.5f, 0.0f);
    }
    if (keyIsPressed(input.translateToKeyID("left"), window)){
        transform += vec3(-0.5f, 0.0f, 0.0f);
    }
    if (keyIsPressed(input.translateToKeyID("right"), window)){
        transform += vec3(0.5f, 0.0f, 0.0f);
    }

    //TESTTETO
    if (keyIsPressed(GLFW_KEY_W, window)){
        teto_transform += vec3(0.0f, 0.5f, 0.0f);
        
    }
    if (keyIsPressed(GLFW_KEY_S, window)){
        teto_transform += vec3(0.0f, -0.5f, 0.0f);
    }
    if (keyIsPressed(GLFW_KEY_A, window)){
        teto_transform += vec3(-0.5f, 0.0f, 0.0f);
    }
    if (keyIsPressed(GLFW_KEY_D, window)){
        teto_transform += vec3(0.5f, 0.0f, 0.0f);
    }

    //TEST PLAYER
    if (player!=nullptr)
    {
        if (keyIsPressed(GLFW_KEY_E, window)){
            player->addHealth(-1*deltaTime);
        }
        if (keyIsPressed(GLFW_KEY_Q, window)){
            player->addHealth(+1*deltaTime);
        }
    }

    // additionally we'll have to process queued non-movement related inputs
    if (!actionQueue.empty())
    {
        
    }
}

// queues non-movement actions from the key callback for processing in the render loop
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action != GLFW_PRESS) {
        return;
    }

    std::string temp = input.translateToAction(key);
    if (temp.empty()) {
        return; // unknown key, no mapped action
    }

    // ignore movement/key actions already handled by processInput
    if (std::find(actionQueueIgnore.begin(), actionQueueIgnore.end(), temp) != actionQueueIgnore.end()) {
        return;
    }

    if (std::find(actionQueue.begin(), actionQueue.end(), temp) == actionQueue.end())
    {
        std::cout << "action queued: " << temp << std::endl;
        actionQueue.push_back(temp);
    }
}


int main()
{
    //random initialization
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Game Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //set up input callbacks
    glfwSetKeyCallback(window, keyCallback);

    // Set up Dear ImGui after GLFW and GLAD. Passing true lets the backend--------------------
    // install its callbacks while preserving the key callback registered above.
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");


    // build and compile our shader program
    // ------------------------------------
#ifdef __APPLE__
    VertexShader vertexShader("../shaders/default.vert");
    FragmentShader fragmentShader("../shaders/default.frag");
#endif

#ifdef _WIN32
    auto exePath = getExecutablePath().parent_path();
    auto shaderDir = exePath / ".." / "shaders";
    VertexShader vertexShader((shaderDir / "default.vert").string().c_str());
    FragmentShader fragmentShader((shaderDir / "default.frag").string().c_str());
#endif

    ShaderProgram shaderProgram(vertexShader, fragmentShader);    // shaderProgram.checkErrors();

    //shaderprogram is now complete

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    // float vertices[] = {
    //      0.5f,  0.5f, 0.0f,  0.7f, 1.0f, // top right
    //      0.5f, -0.5f, 0.0f,  0.8f, 0.2f,// bottom right
    //     -0.5f, -0.5f, 0.0f,  0.1f, 0.0f,// bottom left
    //     -0.5f,  0.5f, 0.0f,  0.3f, 0.9f// top left 
    // };
    // unsigned int indices[] = {  // note that we start from 0!
    //     0, 1, 3,  // first Triangle
    //     1, 2, 3   // second Triangle
    // };

    // //color stuff
    // unsigned int colorLoc = glGetUniformLocation(shaderProgram.getID(), "uColor");
    // vec4 colorValue(//red|green|blue|alpha
    //     1.0f, 
    //     1.0f, 
    //     1.0f, 
    //     1.0f);
    //     // std::cout << "uColor location: " << colorLoc << std::endl;

    //dunno what this does
    //VICTOR COMMENT THIS EXPLAIN WHAT ITS FOR
    GLuint tex0 = glGetUniformLocation(shaderProgram.getID(), "tex0");

    int transformLoc = glGetUniformLocation(shaderProgram.getID(), "transform");
    int scaleLoc = glGetUniformLocation(shaderProgram.getID(), "scale");
    vec3 transform(0.0f);
    vec3 velocity(0.0f);
    float speed = 1.0f;

    //bind textures 
#ifdef _WIN32
    auto mikuTexturePath = exePath / ".." / "textures" / "sega-hatsune-miku-series-hatsune-miku-fuwa-petit-big-jumbo-plush-toy__39402.png";
    Texture texture(mikuTexturePath.string());

    auto tetoTexturePath = exePath / ".." / "textures" / "teto.jpeg";
    Texture teto_texture(tetoTexturePath.string());

    auto playerTexturePath = exePath / ".." / "textures" / "texture.png";
    Texture player_texture(playerTexturePath.string());

#endif
#ifdef __APPLE__
    Texture texture("../textures/sega-hatsune-miku-series-hatsune-miku-fuwa-petit-big-jumbo-plush-toy__39402.png");
    Texture teto_texture("../textures/MODEUS.jpeg");
    Texture player_texture("../textures/texture.png");
#endif
    shaderProgram.use();
    glUniform1i(tex0, 0); // set the texture uniform to texture unit 0


// OBJECT INITALIZATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    Player player(&player_texture);
    objectList.push_back(player);
    player.setScale(vec2(1.0f,0.5f));
    //CREATED MIKU
    Object miku(&texture);
    objectList.push_back(miku);

    Object teto(&teto_texture);
    objectList.push_back(teto);

    vec4 colorValue_prev(
        0.2f, 
        0.5f, 
        0.8f, 
        1.0f
    ); // Initial colorLoc value
    // render loop
    // -----------
    double prevTime = glfwGetTime();

    
    while (!glfwWindowShouldClose(window))
    {
        double currentTime = glfwGetTime();
        float deltaTime = currentTime - prevTime;
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        


        // input
        // -----
        processInput(window, deltaTime, velocity, &player);
        // ImGui::ShowDemoWindow();
        

        // render
        // ------
        glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.use();
        glUniform1i(tex0, 0);
        

        miku.processVelocity(deltaTime, vec2(velocity.x,velocity.y));
        player.processVelocity(deltaTime, vec2(velocity.x,velocity.y));
        velocity = 0;
        teto.processVelocity(deltaTime, vec2(teto_transform.x,teto_transform.y));
        teto_transform=0;
        
        player.draw(transformLoc, scaleLoc);
        teto.draw(transformLoc, scaleLoc);
        miku.draw(transformLoc, scaleLoc);

        

        // Dear ImGui is rendered after the game so the interface appears on top.
        ImGui::Begin("Game controls");
        ImGui::Text("Frame time: %.3f ms", deltaTime * 1000.0f);
        ImGui::Text("Use arrow keys to move the first sprite.");
        ImGui::Text("Use WASD to move the second sprite.");
        if (ImGui::Button("Close game")) {
            glfwSetWindowShouldClose(window, true);
        }
        
        ImGui::End();

        // HEALTH BAR STUFFFF
        //##############//##############//##############//##############//##############//##############

        ImGuiWindowFlags window_flags = 
        ImGuiWindowFlags_NoDecoration | 
        ImGuiWindowFlags_NoInputs | 
        ImGuiWindowFlags_NoSavedSettings | 
        ImGuiWindowFlags_NoFocusOnAppearing | 
        ImGuiWindowFlags_NoBringToFrontOnFocus;
        ImGui::SetNextWindowPos(ImVec2(50, 50), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2(220, 40), ImGuiCond_Always);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));

        ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(82.0f/255.0f,15.0f/255.0f,15.0f/255.0f,1.0f));


        std::cout << player.getHealthPercent() << std::endl;


        if (ImGui::Begin("HealthBarOverlay", nullptr, window_flags)) 
        {
            // Render standard ImGui progress bar
            ImGui::ProgressBar(player.getHealthPercent(), ImVec2(-1.0f, 20.0f), "");
        }
        ImGui::PopStyleColor(2);
        ImGui::End();

        

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
        prevTime = currentTime;
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    // glDeleteVertexArrays(1, &VAO);
    // glDeleteBuffers(1, &VBO);
    // glDeleteBuffers(1, &EBO);

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
