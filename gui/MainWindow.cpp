#include "MainWindow.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_BUTTON(ID_SelectInputFile, MainWindow::OnSelectInputFile)
        EVT_BUTTON(ID_SelectOutputDirectory,
                   MainWindow::OnSelectOutputDirectory)
            EVT_BUTTON(ID_Convert, MainWindow::OnConvert) wxEND_EVENT_TABLE()

                MainWindow::MainWindow(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 235)) {
  wxPanel *panel = new wxPanel(this, wxID_ANY);

  wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

  wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
  wxButton *inputFileButton =
      new wxButton(panel, ID_SelectInputFile, wxT("Select Input File"));
  inputFileTextCtrl = new wxTextCtrl(panel, wxID_ANY);
  hbox1->Add(inputFileButton, 0);
  hbox1->Add(inputFileTextCtrl, 1, wxEXPAND | wxLEFT, 5);
  vbox->Add(hbox1, 0, wxEXPAND | wxALL, 10);

  wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
  wxButton *outputDirButton = new wxButton(panel, ID_SelectOutputDirectory,
                                           wxT("Select Output Directory"));
  outputDirTextCtrl = new wxTextCtrl(panel, wxID_ANY);
  hbox2->Add(outputDirButton, 0);
  hbox2->Add(outputDirTextCtrl, 1, wxEXPAND | wxLEFT, 5);
  vbox->Add(hbox2, 0, wxEXPAND | wxALL, 10);

  wxButton *convertButton = new wxButton(panel, ID_Convert, wxT("Convert"));
  vbox->Add(convertButton, 0, wxALIGN_CENTER | wxALL, 10);

  wxBoxSizer *footerSizer = new wxBoxSizer(wxHORIZONTAL);

  wxStaticText *footerText = new wxStaticText(
      panel, wxID_ANY, "The documentation and source code is available at:");

  footerSizer->Add(footerText, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 0);

  wxHyperlinkCtrl *footerLink = new wxHyperlinkCtrl(
      panel, wxID_ANY, "https://github.com/litalbarkai/redatam-converter",
      "https://github.com/litalbarkai/redatam-converter");

  footerSizer->Add(footerLink, 0, wxALIGN_CENTER_VERTICAL);

  vbox->Add(footerSizer, 0, wxALIGN_CENTER | wxALL, 0);

  panel->SetSizer(vbox);
}

void MainWindow::OnSelectInputFile(wxCommandEvent &event) {
  wxFileDialog openFileDialog(this, _("Select Input File"), "", "",
                              "Dictionary Files (*.dic;*.dicx)|*.dic;*.dicx",
                              wxFD_OPEN | wxFD_FILE_MUST_EXIST);
  if (openFileDialog.ShowModal() == wxID_CANCEL)
    return;

  inputFileTextCtrl->SetValue(openFileDialog.GetPath());
}

void MainWindow::OnSelectOutputDirectory(wxCommandEvent &event) {
  wxDirDialog openDirDialog(this, _("Select Output Directory"), "",
                            wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
  if (openDirDialog.ShowModal() == wxID_CANCEL)
    return;

  outputDirTextCtrl->SetValue(openDirDialog.GetPath());
}

void MainWindow::OnConvert(wxCommandEvent &event) {
  wxString inputFilePath = inputFileTextCtrl->GetValue();
  wxString outputDirPath = outputDirTextCtrl->GetValue();

  if (inputFilePath.IsEmpty() || outputDirPath.IsEmpty()) {
    wxMessageBox("Please select both input file and output directory.", "Error",
                 wxOK | wxICON_ERROR);
    return;
  }

  wxString command = wxString::Format("./redatam \"%s\" \"%s\"/", inputFilePath,
                                      outputDirPath);
  long result = wxExecute(command, wxEXEC_SYNC);

  if (result != 0) {
    wxMessageBox(
        "Conversion failed. Please check the input file and output directory.",
        "Error", wxOK | wxICON_ERROR);
  } else {
    wxMessageBox("Conversion successful!", "Success",
                 wxOK | wxICON_INFORMATION);
  }
}
