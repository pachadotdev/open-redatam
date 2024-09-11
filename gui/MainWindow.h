#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <wx/hyperlink.h>
#include <wx/wx.h>

class MainWindow : public wxFrame {
public:
  MainWindow(const wxString &title);

private:
  void OnSelectInputFile(wxCommandEvent &event);
  void OnSelectOutputDirectory(wxCommandEvent &event);
  void OnConvert(wxCommandEvent &event);
  void OnAbout(wxCommandEvent &event);

  wxTextCtrl *inputFileTextCtrl;
  wxTextCtrl *outputDirTextCtrl;

  wxDECLARE_EVENT_TABLE();
};

enum { ID_SelectInputFile = 1, ID_SelectOutputDirectory, ID_Convert };

#endif // MAINWINDOW_H
