#include "MoosetestApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<MoosetestApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

MoosetestApp::MoosetestApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  MoosetestApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  MoosetestApp::associateSyntax(_syntax, _action_factory);
}

MoosetestApp::~MoosetestApp()
{
}

// External entry point for dynamic application loading
extern "C" void MoosetestApp__registerApps() { MoosetestApp::registerApps(); }
void
MoosetestApp::registerApps()
{
  registerApp(MoosetestApp);
}

// External entry point for dynamic object registration
extern "C" void MoosetestApp__registerObjects(Factory & factory) { MoosetestApp::registerObjects(factory); }
void
MoosetestApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void MoosetestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { MoosetestApp::associateSyntax(syntax, action_factory); }
void
MoosetestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
