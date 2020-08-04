cmake_minimum_required(VERSION 3.16)
project(FinalProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(Common)
include_directories(Controls)
include_directories(FinalProject)

add_executable(FinalProject
        Common/Control.cpp
        Common/Control.h
        Common/EventEngine.cpp
        Common/EventEngine.h
        Common/Graphics.cpp
        Common/Graphics.h
        Controls/Label.cpp
        Controls/Label.h
        FinalProject/Source.cpp
        Common/Border/Border.h
        Common/Border/Border.cpp
        Common/Border/SingleBorder.h
        Common/Border/SingleBorder.cpp
        Common/Border/DoubleBorder.cpp
        Common/Border/DoubleBorder.h
        Controls/Radiobox.h
        Controls/Radiobox.cpp
        Controls/Button.cpp
        Controls/Button.h Controls/Panel.cpp Controls/Panel.h Controls/Textbox.cpp Controls/Textbox.h Controls/NumericBox.cpp Controls/NumericBox.h Controls/ButtonListener.h Controls/Checklist.cpp Controls/Checklist.h Controls/ListItem.cpp Controls/ListItem.h Controls/Messagebox.cpp Controls/Messagebox.h)
