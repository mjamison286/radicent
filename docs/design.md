# Overall Design 

This project divides everything into its own separate file, from handling user io to logging.

## CPP Files

* main.cpp
* io.cpp
* gui.cpp
* log.cpp

### main.cpp

#### Global Variables

* ctrlPressed - boolean variable to hold whether or not a control key is currently being pressed.

#### Functions

* void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
  * This function serves as the key callback for the glfw window. This function is required to query user input in the gui.
* int main(int argc, char* argv[]);
  * This function is the main function of the program. This function determines the lifetime of the program.


### io.cpp

#### Global Variables

* isVerbose - boolean variable to hold whether or not the user decided to run the program in verbose mode. Verbose mode enables extra logging explaining exactly what is going on behind the scenes.
* debugMode - boolean variable to hold whether or not the user decided to run the program in debug mode. Debug mode enables extra features that allow for quicker development

#### Functions

* void processCLI(int argc, char* argv[]);
  * This function parses through the command line input given by the user to open the program. This function is only called by the main function, where the main function's parameters are passed straight through to this function to get processed. Both of the global boolean variables are set using these flags, as well as the input and output paths for the file currently being worked on. 

  * int argc - count of arguments given by the user through the command line.
  * char* argv[] - array of individual strings given by the user through the command line.

* void writeToFile(std::string content, std::string path);
  * This function takes in a string through the parameter content, and opens and writes the content to a file specified by the parameter path. This function is currently only called from gui.cpp, where the user can press a gui button to save content to the file.

  * std::string content - the string that should be written to the file.
  * std::string path - the path of the file that should be written to.

* std::string writeToUnknownPath(std::string content);
  * This function takes in a string through the parameter content, and querys the user for a path to save the content to. Once the user enters a path, the function will then just call writeToFile(); with the output path that they entered. This function is currently unused, but will be utilized in the future.

  * std::string content - the string that should be written to the file.

  * returns the path that the user entered.

* std::string readFromFile(std::string path);
  * This function takes in a string through the parameter path, and tries to open a file located at that filepath. If successful, the program then reads the file line by line and concatenates the contents into a std::string called content. This function is currently unused but will be utilized in the future.

  * std::string path - the path of the file that should be read from.

  * returns the contents of the file specified.


### gui.cpp

#### Global Variables

* showdemowindow - boolean which holds whether or not the demo window should be shown.

#### Functions

* bool setupGLFW(GLFWwindow** window);
  * This function takes in a double GLFWwindow pointer, which holds the memory address of the GLFWwindow* that is declared in main.cpp. This function initializes GLFW to work with the same window that main uses, and actually creates the window using opengl.

  * GLFWwindow** window - the memory address of the GLFWwindow* that main uses across the entirety of the gui. This is shared between the whole program, so the window needs to stay the same.

  * returns true if GLFW was properly set up and the window was created properly, returns false otherwise.

* bool setupImGui(GLFWwindow** window);
  * This function takes in a double GLFWwindow pointer, which holds the memory address of the GLFWwindow* that is declared in main.cpp. This function initializes ImGui to work with the same window that main uses, and creates the ImGui context for which all of the immediate mode gui will be rendered to.

  * GLFWwindow** window - the memory address of the GLFWwindow* that main uses across the entirety of the gui. This is shared between the whole program, so the window needs to stay the same.

  * returns true if ImGui was properly set up with the current window, returns false otherwise.

* void initGui(GLFWwindow** window);
  * This function takes in a double GLFWwindow pointer, which holds the memory address of the GLFWwindow* that is declared in main.cpp. This function just calls both setupGLFW(); and setupImGui();, and checks whether both give a proper return value.

  * GLFWwindow** window - the memory address of the GLFWwindow* that main uses across the entirety of the gui. This is shared between the whole program, so the window needs to stay the same.

* bool renderGui(GLFWwindow** window);
  * This function takes in a double GLFWwindow pointer, which holds the memory address of the GLFWwindow* that is declared in main.cpp. This function calls all of the ImGui functions that you want to render the immediate mode gui that you need. This function also swaps the glfw buffers so everything is properly displayed to the screen.

  * GLFWwindow** window - the memory address of the GLFWwindow* that main uses across the entirety of the gui. This is shared between the whole program, so the window needs to stay the same.

  * returns true

* void cleanupGui(GLFWwindow** window);
  * This function takes in a double GLFWwindow pointer, which holds the memory address of the GLFWwindow* that is declared in main.cpp. This function makes sure that both GLFW and ImGui are properly shut down in order to make sure that the program ends cleanly. First the ImGui context is destroyed, and then the GLFW window is destroyed and terminated.

  * GLFWwindow** window - the memory address of the GLFWwindow* that main uses across the entirety of the gui. This is shared between the whole progran, so the window needs to stay the same.


### log.cpp

#### Functions

* void logFatal(std::string str);
  * This function takes in a string message that should be displayed to the console. This function then writes the tag FATAL: and then the message given to a predetermined log file, and then prints that same log message to the console. The program is then exited with the exit code EXIT_FAILURE, defined by the header <cstdlib>

  * std::string str - the message that should be logged to both the log file and the console.

* void logWarning(std::string str);
  * This function takes in a string message that should be displayed to the console. This function then writes the tag WARNING: and then the message given to a predetermined log file, and then prints that same log message to the console.

  * std::string str - the message that should be logged to both the log file and the console.

* void logVerbose(std::string str);
  * This function takes in a string message that should be displayed to the console. This function then writes the tag LOG: and then the message given to a predetermined log file, and then prints that same log message to the console. This function is ONLY called when the isVerbose boolean variable is set to true by the user input given and processed by processCLI();, found in io.cpp.

  * std::string str - the message that should be logged to both the log file and the console.


## Header Files

* global.hpp
* io.hpp
* gui.hpp
* log.hpp

### global.hpp

#### Static Variables

* These are single variables that are used throughout the program and should only have one state throughout the entire program at one time.

* static std::string inputPath - the path to the file used for input.
* static std::string outputPath - the path to the output location.

#### Externed Variables

* WIP

* extern bool isSaved - bool variable which holds whether the current file is saved or not.
* extern bool isVerbose - bool variable which holds whether or not the program is currently in verbose mode or not. See io.cpp.
* extern bool debugMode - bool variable which holds whether or not the program is currently in debug mode or not. See io.cpp.


### io.hpp 

* See the entry for io.cpp.


### gui.hpp 

* See the entry for gui.cpp.


### log.hpp

* See the entry for log.cpp.