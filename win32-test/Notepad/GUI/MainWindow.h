#pragma once

#include <util/Win/GUI/Window.h>
#include <util/Win/GUI/Edit.h>
#include <memory>
#include <functional>

namespace WIN32TEST {
namespace Notepad {
namespace GUI {

enum class Page
{
    Portrait, 
    Landscape
};

class MainWindow : public Util::Win::GUI::Window
{
public:
    MainWindow(HWND hwnd, HANDLE process);
    ~MainWindow();

public:  // public typedefs
    typedef std::function<void(bool, const std::string &)>  OnCondition;
    typedef OnCondition                                     OnSaved;
    typedef OnCondition                                     OnReplaceAll;
    typedef OnCondition                                     OnSetPageOreintation;
    typedef Util::Win::GUI::Edit                            Edit;

public:  // interface
    void saveAs(const std::string &path, OnSaved);
    void write(const std::string &text);
    std::string read();
    void replaceAll(
        const std::string &findWhat,
        const std::string &replaceWith,
        bool matchCase,
        OnReplaceAll);
    void setPageOrientation(Page page, OnSetPageOreintation);
    void exitWithoutSaving();

private: // private structs
    enum CtrlsId
    {
        New         = 1,
        Open        = 2,
        Save        = 3,
        SaveAs      = 4,
        PageSetup   = 5,
        Exit        = 7,
        Document    = 15,
        Replace     = 23
    };

private: // member variables
    HANDLE  _process;
    Edit    _document;
};

typedef std::shared_ptr<MainWindow> MainWindowPtr;

} // namespace GUI
} // namespace Notepad
} // namespace WIN32TEST
