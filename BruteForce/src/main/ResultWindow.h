#ifndef RESULTWIDOW_H_
#define RESULTWINDOW_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_RGB_Image.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input_.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Chart.H>
#include "Project.h"

using namespace std;

class ResultWindow {

	static void static_saveClicked(Fl_Widget *w, void *data) {
		((ResultWindow*) data)->saveClicked(w);
	}

	void saveClicked(Fl_Widget *w);

	static void static_exitClicked(Fl_Widget *w, void *data) {
		((ResultWindow*) data)->exitClicked(w);
	}

	void exitClicked(Fl_Widget *w);

	int teamScoreAvg, bestScore, badScore;
	int bestTeam, worstTeam, percent, notAssign;
	int low1, low2, avg1, avg2, high1, high2;

public:
	static int permutations;
	static int swaps;
	static int count;
	static int project_pool[5][200];

	Fl_Window *windowResult;
	Fl_Text_Display *textDisplay;
	Fl_Text_Buffer *buffer;
	Fl_Button *buttonSave, *buttonExit;
	Fl_Box *permBox, *swapBox;
	Fl_Box *teamBox, *bestBox, *badBox;
	Fl_Box *spacer, *borderBox;
	Fl_Box *labelBox3, *labelBox4, *labelBox5;
	Fl_Box *labelBox1, *labelBox2;
	Fl_Chart *pieChart, *barChart, *classChart;

	ResultWindow();
	~ResultWindow();
	void addText();
	void calculateStats();

};

#endif /*SRC_MAIN_RESULTWINDOW_H_*/
