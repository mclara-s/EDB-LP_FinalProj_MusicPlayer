#include "src/application.h"
#include "src/main_window.h"

int main(int argc, char *argv[])
{
  Application a(argc, argv);
  MainWindow window;

  window.show();

  return a.exec();
}