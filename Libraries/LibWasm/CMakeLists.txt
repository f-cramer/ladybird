set(SOURCES
    AbstractMachine/AbstractMachine.cpp
    AbstractMachine/BytecodeInterpreter.cpp
    AbstractMachine/Configuration.cpp
    AbstractMachine/Validator.cpp
    Parser/Parser.cpp
    Printer/Printer.cpp
)

if (NOT WIN32)
    list(APPEND SOURCES WASI/Wasi.cpp)
endif()

ladybird_lib(LibWasm wasm)
target_link_libraries(LibWasm PRIVATE LibCore)

include(wasm_spec_tests)
