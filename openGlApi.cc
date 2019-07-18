#include "openGlApi.h"
#include <node.h>
#include <v8.h>
#include <GL/glut.h>
#include <iostream>

using v8::Persistent;
using v8::ObjectTemplate;
using v8::Local;
using v8::Isolate;
using v8::String;
using v8::NewStringType;
using v8::Context;
using v8::FunctionTemplate;
using v8::FunctionCallbackInfo;
using v8::Value;
using v8::Data; 
using v8::Number;
using v8::FunctionCallback;
using v8::HandleScope;
using v8::Context;
using v8::Object;
using v8::Function;
using v8::EscapableHandleScope ; 

Glut::Glut(){};
Glut::~Glut(){};

Persistent<Function> Glut::constructor ;

void test(const FunctionCallbackInfo<Value>& args){
     Isolate* isolate = Isolate::GetCurrent();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "test"));
    
}

Local<Function> Glut::Init(int* argc ,char** argv){
    Isolate* isolate = Isolate::GetCurrent();
    EscapableHandleScope handleScope(isolate);
    Local<FunctionTemplate> tpl= FunctionTemplate::New(isolate);
    tpl->Set(String::NewFromUtf8(isolate,"InitGlut",NewStringType::kNormal).ToLocalChecked(),Glut::InitGlut(argc,argv));
    tpl->Set(String::NewFromUtf8(isolate,"InitGlut",NewStringType::kNormal).ToLocalChecked(),Glut::InitGlut(argc,argv));
    Local<Function> fn = tpl->GetFunction();

    constructor.Reset(isolate, fn);
    return handleScope.Escape(fn);
}

Local<FunctionTemplate> Glut::InitGlut(int* argc,char** argv){
    Glut::CreateWindowGlut(argc,argv);  
    std::cout << "hello";
}

Local<FunctionTemplate> Glut::CreateWindowGlut(int* argc,char** argv){
    glutInit(argc, argv);                 // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutDisplayFunc(Glut::Display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the infinitely event-processing loop
}


void Glut::Display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
 
   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
   glEnd();
 
   glFlush();  // Render now

}

Local<Function> Glut::GetContext(Local<Function> globalGlut){
    Isolate* isolate = Isolate::GetCurrent();
    EscapableHandleScope handleScope(isolate);
    Local<Context> context = isolate->GetCurrentContext();
    Local<Function> tpl = Local<Function>::New(isolate, globalGlut);
    return handleScope.Escape(tpl);
}