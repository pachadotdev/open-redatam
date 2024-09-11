#include <wx/wx.h>

#include "MainWindow.h"

class MyApp : public wxApp {
public:
  virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  MainWindow *mainWindow = new MainWindow("Redatam Converter");
  mainWindow->Show(true);
  return true;
}
