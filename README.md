# UDP Server in C++

This program is a simple UDP server that receives packets containing three floating-point numbers separated by commas. The server runs in a separate thread, allowing the main program to perform other tasks.

## Dependencies

- C++ Compiler with C++14 support.
- [Boost](https://www.boost.org/) libraries (version 1.65.1 or later) with `system` and `thread` components.

## Building

To build this program, we will use [CMake](https://cmake.org/) (version 3.10 or later).

1. Clone the repository or download the source code.
2. Navigate to the source code directory.
3. Create a new directory for the build outputs:

    ```bash
    mkdir build
    cd build
    ```

4. Run CMake to generate the Makefile, then run `make` to build the project:

    ```bash
    cmake ..
    make
    ```

5. You should now have the executable named `UDPServer` in the `build` directory.

## Running

To run the UDP Server, execute the following command:

```bash
./UDPServer
