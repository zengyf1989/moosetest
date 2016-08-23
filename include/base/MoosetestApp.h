#ifndef MOOSETESTAPP_H
#define MOOSETESTAPP_H

#include "MooseApp.h"

class MoosetestApp;

template<>
InputParameters validParams<MoosetestApp>();

class MoosetestApp : public MooseApp
{
public:
  MoosetestApp(InputParameters parameters);
  virtual ~MoosetestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MOOSETESTAPP_H */
