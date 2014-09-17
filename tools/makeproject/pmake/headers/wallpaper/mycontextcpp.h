const char MYCONTEXTCPP_STR[] = 
"// mycontext.cpp\n"
"%s\n"
"//\n"
"\n"
"#include \"mycontext.h\"\n"
"\n"
"#include \"myscene.h\"\n"
"\n"
"#include <Paper3D/paper3d.h>\n"
"\n"
"#include <PFoundation/pfoundation.h>\n"
"\n"
"\n"
"MyContext::MyContext(const PContextProperties &properties)\n"
"    : PContext(properties)\n"
"{\n"
"    m_scene = P_NULL;\n"
"}\n"
"\n"
"MyContext::~MyContext()\n"
"{\n"
"}\n"
"\n"
"pbool MyContext::onInitialized()\n"
"{\n"
"    m_scene = PNEW(MyScene(this));\n"
"    PSceneManager *sceneMgr = module<PSceneManager>(\"scene-manager\");\n"
"    sceneMgr->addScene(m_scene);\n"
"    sceneMgr->setMainScene(m_scene);\n"
"\n"
"    return true;\n"
"}\n"
"\n"
"pbool MyContext::onUpdate()\n"
"{\n"
"    return true;\n"
"}\n"
"\n"
"void MyContext::onDestroy()\n"
"{\n"
"}\n"
"\n"
"pbool MyContext::onKeyboard(PEvent *event)\n"
"{\n"
"    pint32 key = event->parameter(P_EVENTPARAMETER__KEY_SCANCODE).toInt();\n"
"    pint32 type = event->getType();\n"
"    if (type == P_EVENT__KEYUP)\n"
"    {\n"
"        switch (key)\n"
"        {\n"
"            case P_KEY_ESC:\n"
"                quit();\n"
"                return true; \n"
"        }\n"
"    }\n"
"    return true;\n"
"}";