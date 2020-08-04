#include <Border/DoubleBorder.h>
#include <Panel.h>
#include <Button.h>
#include <Textbox.h>
#include <Messagebox.h>
#include <Border/SingleBorder.h>
#include <NumericBox.h>
#include <Checklist.h>
#include <Radiobox.h>
#include "../Common/EventEngine.h"

int main(int argc, char** argv)
{
    Panel panel(new DoubleBorder,Color::Blue,Color::Green);
	Label l("Label Sample",5,2,new DoubleBorder,Color::Orange,Color::White);
    panel.addControl(&l);
    Button button("Button Sample","sample",5,6,new DoubleBorder,Color::Green,Color::White);
    panel.addControl(&button);
    Textbox textbox(10,5,10,new SingleBorder,Color::Red,Color::White);
    panel.addControl(&textbox);
    NumericBox numericBox(10,0,30,5,new DoubleBorder,Color::Green,Color::White);
    panel.addControl(&numericBox);
    Checklist checklist({"Check one","Check Two","Check Three"},50,5,20,new DoubleBorder, Color::Blue, Color::Green);
    panel.addControl(&checklist);
    Radiobox radiobox({"Radio one","Radio Two","Radio Three"},75,5,20,new DoubleBorder, Color::Blue, Color::Green);
    panel.addControl(&radiobox);
    Messagebox messagebox("Are you sure you want to save",5,15,new DoubleBorder,Color::Orange,Color::White);
    panel.addControl(&messagebox);
	EventEngine e;
	e.run(panel);
}