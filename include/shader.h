#pragma once
// or use traditional include guards:
// #ifndef SHADER_H
// #define SHADER_H

#include <string>

// --- Function Declarations ---

/**
 * @brief Reads the entire content of a file into a string.
 * @param filePath Path to the file.
 * @return String containing file contents, or an empty string on failure.
 */
std::string readFileToString(const std::string& filePath);

/**
 * @brief Checks for OpenGL shader compilation or program linking errors.
 * @param shader The ID of the shader or program (must be a valid GLuint).
 * @param type The type ("VERTEX", "FRAGMENT", or "PROGRAM") for logging.
 */
void checkCompileErrors(unsigned int shader, const std::string& type);


// --- Class Definition ---

/**
 * @brief A class to encapsulate an OpenGL shader program.
 *
 * This class handles reading, compiling, and linking vertex and fragment
 * shaders into a single shader program. It also provides utility functions
 * for setting uniform variables.
 */
class Shader {
public:
    // The shader program's OpenGL ID
    unsigned int ID;

    /**
     * @brief Constructor that builds the shader program from source files.
     * @param vertexPath Path to the vertex shader source code.
     * @param fragmentPath Path to the fragment shader source code.
     */
    Shader(const char* vertexPath, const char* fragmentPath);

    /**
     * @brief Activates this shader program for use in rendering.
     */
    void use();

    // --- Utility Uniform Setters ---

    /**
     * @brief Sets a boolean uniform variable in the shader.
     * @param name The name of the uniform in the shader code.
     * @param value The value to set.
     */
    void setBool(const std::string &name, bool value) const;

    /**
     * @brief Sets an integer uniform variable in the shader.
     * @param name The name of the uniform in the shader code.
     * @param value The value to set.
     */
    void setInt(const std::string &name, int value) const;

    /**
     * @brief Sets a float uniform variable in the shader.
     * @param name The name of the uniform in the shader code.
     * @param value The value to set.
     */
    void setFloat(const std::string &name, float value) const;

    // Note: The private 'checkCompileErrors' declaration from your
    // original class was removed. The constructor will call the
    // global 'checkCompileErrors' function declared above.
};

// #endif // SHADER_H (if using traditional guards)