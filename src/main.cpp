#include <glad/glad.h>
#include <GLFW/glfw3.h>
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

#include "Texture.h"

#include "vector.h"


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

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


//we no longer have a use for these,
//instead, the vert and frag shader TEXT FILES will be used
// const char *vertexShaderSource = "#version 330 core\n"
//     "layout (location = 0) in vec3 aPos;\n"
//     "void main()\n"
//     "{\n"
//     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//     "}\0";
// const char *fragmentShaderSource = "#version 330 core\n"
//     "out vec4 FragColor;\n"
//     "void main()\n"
//     "{\n"
//     "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//     "}\n\0";

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

    // unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // glCompileShader(vertexShader);
    // // check for shader compile errors
    // int success;
    // char infoLog[512];
    // glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    // if (!success)
    // {
    //     glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    //     std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    // }
    // fragment shader
    // unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    // glCompileShader(fragmentShader);
    // // check for shader compile errors
    // glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    // if (!success)
    // {
    //     glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    //     std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    // }
    // // link shaders
    // unsigned int shaderProgram = glCreateProgram();
    // glAttachShader(shaderProgram, vertexShader.getID());
    // glAttachShader(shaderProgram, fragmentShader.getID());
    // glLinkProgram(shaderProgram);
    // // check for linking errors

    // int success;
    // char infoLog[512];

    // glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    // if (!success) {
    //     glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    //     std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    // }
    // glDeleteShader(vertexShader.getID());
    // glDeleteShader(fragmentShader.getID());

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
         0.5f,  0.5f, 0.0f,  0.7f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,  0.7f, 0.0f,// bottom right
        -0.5f, -0.5f, 0.0f,  0.3f, 0.0f,// bottom left
        -0.5f,  0.5f, 0.0f,   0.3f, 1.0f// top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    //color stuff
    unsigned int color = glGetUniformLocation(shaderProgram.getID(), "uColor");
    vec4 colorValue(//red|green|blue|alpha
        1.0f, 
        1.0f, 
        1.0f, 
        1.0f);
        // std::cout << "uColor location: " << color << std::endl;

    GLuint tex0 = glGetUniformLocation(shaderProgram.getID(), "tex0");

    
    VAO vao;
    vao.bind();

    VBO vbo(vertices, sizeof(vertices));
    EBO ebo(indices, sizeof(indices));

    vao.linkAttrib(vbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0); // position attribute
    vao.linkAttrib(vbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float))); // texture coord attribute
    vao.unbind();
    vbo.unbind();
    ebo.unbind();

    auto texturePath = exePath / ".." / "textures" / "sega-hatsune-miku-series-hatsune-miku-fuwa-petit-big-jumbo-plush-toy__39402.png";
    Texture texture(texturePath.string());
    shaderProgram.use();
    glUniform1i(tex0, 0); // set the texture uniform to texture unit 0


    // glGenVertexArrays(1, &VAO);
    // glGenBuffers(1, &VBO);
    // glGenBuffers(1, &EBO);
    // // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    // glBindVertexArray(VAO);

    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    // glEnableVertexAttribArray(0);

    // // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    // glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    // //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0); 


    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    vec4 colorValue_prev(
        0.2f, 
        0.5f, 
        0.8f, 
        1.0f
    ); // Initial color value
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        colorValue.x = std::min(std::clamp(dis(gen),colorValue_prev.x - 0.01f, colorValue_prev.x + 0.01f), 0.9f); // Random red component
        colorValue.y = std::min(std::clamp(dis(gen),colorValue_prev.y - 0.01f, colorValue_prev.y + 0.01f), 0.9f); // Random green component
        colorValue.z = std::min(std::clamp(dis(gen),colorValue_prev.z - 0.01f, colorValue_prev.z + 0.01f), 0.9f); // Random blue component

        colorValue_prev = colorValue; // Update previous color value

        shaderProgram.use();
        glUniform4f(color, colorValue.x, colorValue.y, colorValue.z, colorValue.w);

        shaderProgram.use();
        glUniform1i(tex0, 0); // set the texture uniform to texture unit 0
        texture.bind();
        
        // glUniform4f(color, 0, 0, 0, 0);

        shaderProgram.use();
        vao.bind(); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0); // no need to unbind it every time 
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    // glDeleteVertexArrays(1, &VAO);
    // glDeleteBuffers(1, &VBO);
    // glDeleteBuffers(1, &EBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

