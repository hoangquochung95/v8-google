cmd_Release/obj.target/addon2.node := g++ -shared -pthread -rdynamic -m64  -Wl,-soname=addon2.node -o Release/obj.target/addon2.node -Wl,--start-group Release/obj.target/addon2/test.o Release/obj.target/addon2/openGlAddon.o Release/obj.target/addon2/openGlApi.o -Wl,--end-group -lglut -lGL -lGLU