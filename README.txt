Java-to-C++ conversion

Files included:
- main.cpp: equivalent entry point for the empty Java main method.
- Token.h / Token.cpp: converted Token class.
- Scanner.h: Scanner class with a std::queue<Token>, interpreting the incomplete Java `queue` line as a queue of tokens.
- The remaining .h files correspond to the empty Java classes.

Important:
Most original Java classes were empty, so their C++ equivalents are empty too. The original Scanner.java contained only the incomplete text `queue`, so the queue type was inferred as std::queue<Token>. Adjust it if your intended queue stores a different type.

Compile with a C++17 compiler, for example:
g++ -std=c++17 main.cpp Token.cpp -o MyApp.exe

If your project uses the other class headers, include them in the relevant .cpp files. For a larger project, compile all .cpp files together.
