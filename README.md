# Match3 Game

This project implements a Match-3 game using C++ with a focus on software design patterns and unit testing. It serves as a practical example for developers interested in game development and design pattern application.

## Features

- **Design Patterns**:
  - *Command Pattern*: Encapsulates game actions as command objects, promoting flexibility and extensibility.
  - *Model-View-Controller (MVC)*: Separates game data (Model), user interface (View), and control logic (Controller) to enhance modularity.
  - *Builder Pattern*: Simplifies the creation of complex game objects by separating their construction from representation.

- **Graph Representation**:
  - Utilizes an undirected graph with an adjacency list to model the game board.
  - Employs Depth-First Search (DFS) for efficient traversal and matching detection.

- **Unit Testing**:
  - Incorporates the Google Test framework to ensure code reliability and correctness.

## Prerequisites

- C++11 or higher
- Google Test framework

## Getting Started

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/youssefmyh/Match3.git
   ```
   This command will download the project files to your local machine.

2. **Navigate to the Project Directory**:
   ```bash
   cd Match3
   ```

3. **Build the Project**:
   - Ensure the Google Test framework is installed and configured in your development environment.
   - Use your preferred build system to compile the project.

4. **Run Unit Tests**:
   - Execute the test suite to verify functionality.

## Project Structure

- `Game/`: Contains the core game logic and implementation of design patterns.
- `.gitignore`: Specifies files and directories to be ignored by Git.
- `README.md`: This readme file.
- `graph1.png`: ![Graph Structure](https://github.com/youssefmyh/Match3/raw/main/graph1.png)
- `nodes.png`: ![Nodes Representation](https://github.com/youssefmyh/Match3/raw/main/nodes.png)
- `screen.png`: ![Game Screen](https://github.com/youssefmyh/Match3/raw/main/screen.png)

## How It Works

- **Game Board Representation**: The game board is modeled as an undirected graph using an adjacency list, where each node represents a tile, and edges denote possible connections.

- **Matching Algorithm**: A Depth-First Search (DFS) algorithm traverses the graph to identify and handle matches, ensuring an efficient matching process.

- **Design Pattern Integration**: The Command Pattern manages user actions, MVC architecture separates concerns for better code organization, and the Builder Pattern facilitates the creation of complex game elements.

## Contributing

Contributions are welcome! Feel free to fork this repository, make enhancements, and submit pull requests.

## License

This project is licensed under the MIT License.

## Acknowledgments

- [Google Test](https://github.com/google/googletest) for the unit testing framework.

For more information, visit the [GitHub repository](https://github.com/youssefmyh/Match3).
