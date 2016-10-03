project(eca419_exercicio01)
cmake_minimum_required(VERSION 2.8)
include_directories(include src)
set(H_FILES
	 include/eca419/exercicio01/CPF.h
	 include/eca419/exercicio01/CNH.h
	 include/eca419/exercicio01/Documento.h
	 include/eca419/exercicio01/DocumentoIdentificador.h
	 include/eca419/exercicio01/EnumConversor.h
	 include/eca419/exercicio01/Pessoa.h
	 include/eca419/exercicio01/RG.h
	 include/eca419/exercicio01/sexos/SexoConversor.h
	 include/eca419/exercicio01/sexos/SexoEnum.h
)
set(CPP_FILES
	 src/eca419/exercicio01/CPF.cpp
	 src/eca419/exercicio01/CNH.cpp
	 src/eca419/exercicio01/Documento.cpp
	 src/eca419/exercicio01/DocumentoIdentificador.cpp
	 src/eca419/exercicio01/Pessoa.cpp
	 src/eca419/exercicio01/RG.cpp
	 src/eca419/exercicio01/sexos/SexoConversor.cpp
)
add_executable(${PROJECT_NAME} src/main.cpp ${H_FILES} ${CPP_FILES})
