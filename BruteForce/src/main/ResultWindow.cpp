/*
 * ResultWindow.cpp
 *
 * Description:  prints out the team assignment results for the user to review
 *
 *
 * Created on:   01/29/2020
 *
 * Authors:   M. Cilibra, M. Colina, C. DeLeo, E. Marquise, S. Rogers
 *
 * List of functions:
 *
 */

#include "ResultWindow.h"
#include "main.h"
#include "GUIStyles.h"
#include "Project.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_RGB_Image.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input_.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Chart.H>

using namespace std;

//Function to convert integers into constant expressions.
constexpr int toConstInt(int constInt) {
	return constInt;
}


/* constructor, preps the results window and buffer */
ResultWindow::ResultWindow() {

	// MAIN WINDOW
	windowResult = new Fl_Window(1500, 800, "Capstone Team Assignment Results");

	Fl_Box *backBox1 = new Fl_Box(0, 0, 10, 800);
	backBox1->box(FL_FLAT_BOX);
	backBox1->color(ASU_BLACK);

	Fl_Box *backBox2 = new Fl_Box(0, 0, 1500, 10);
	backBox2->box(FL_FLAT_BOX);
	backBox2->color(ASU_BLACK);

	Fl_Box *backBox3 = new Fl_Box(0, 790, 1000, 10);
	backBox3->box(FL_FLAT_BOX);
	backBox3->color(ASU_BLACK);

	// Buffer
	buffer = new Fl_Text_Buffer();
	borderBox = new Fl_Box(860, 0, 640, 800);
	borderBox->box(FL_FLAT_BOX);
	borderBox->color(ASU_BLACK);

	//Text Display
	textDisplay = new Fl_Text_Display(870, 10, 620, 780);
	textDisplay->buffer(buffer);
	textDisplay->textfont(FL_HELVETICA);
	textDisplay->textsize(15);
	textDisplay->selection_color(ASU_GOLD);

	//Save BUTTON
	buttonSave = new Fl_Button(485, 20, 175, 50, "Save .csv Report");
	buttonSave->color(ASU_GOLD);
	buttonSave->labelfont(FL_HELVETICA);
	buttonSave->labelcolor(ASU_BLACK);
	buttonSave->labelsize(15);
	buttonSave->selection_color(ASU_BLACK);
	buttonSave->callback(static_saveClicked, this);

	//Exit BUTTON
	buttonExit = new Fl_Button(675, 20, 175, 50, "Exit");
	buttonExit->color(ASU_GOLD);
	buttonExit->labelfont(FL_HELVETICA);
	buttonExit->labelcolor(ASU_BLACK);
	buttonExit->labelsize(15);
	buttonExit->selection_color(ASU_BLACK);
	buttonExit->callback(static_exitClicked, this);

	permBox = new Fl_Box(10, 20, 5, 20, "");
	permBox->box(FL_FLAT_BOX);
	permBox->color(ASU_GREY);
	permBox->align(FL_ALIGN_RIGHT);
	permBox->labelfont(FL_HELVETICA_BOLD);
	permBox->labelsize(15);
	permBox->labelcolor(ASU_WHITE);

	swapBox = new Fl_Box(10, 50, 5, 20, "");
	swapBox->box(FL_FLAT_BOX);
	swapBox->color(ASU_GREY);
	swapBox->align(FL_ALIGN_RIGHT);
	swapBox->labelfont(FL_HELVETICA_BOLD);
	swapBox->labelsize(15);
	swapBox->labelcolor(ASU_WHITE);

	teamBox = new Fl_Box(330, 85, 5, 20, "");
	teamBox->box(FL_FLAT_BOX);
	teamBox->color(ASU_GREY);
	teamBox->align(FL_ALIGN_RIGHT);
	teamBox->labelfont(FL_HELVETICA_BOLD);
	teamBox->labelsize(15);
	teamBox->labelcolor(ASU_WHITE);

	bestBox = new Fl_Box(580, 85, 5, 20, "");
	bestBox->box(FL_FLAT_BOX);
	bestBox->color(ASU_GREY);
	bestBox->align(FL_ALIGN_RIGHT);
	bestBox->labelfont(FL_HELVETICA_BOLD);
	bestBox->labelsize(15);
	bestBox->labelcolor(ASU_WHITE);

	badBox = new Fl_Box(10, 85, 5, 20, "");
	badBox->box(FL_FLAT_BOX);
	badBox->color(ASU_GREY);
	badBox->align(FL_ALIGN_RIGHT);
	badBox->labelfont(FL_HELVETICA_BOLD);
	badBox->labelsize(15);
	badBox->labelcolor(ASU_WHITE);

	labelBox1 = new Fl_Box(30, 130, 5, 20, "Number of Teams within Score Range");
	labelBox1->box(FL_FLAT_BOX);
	labelBox1->color(ASU_GREY);
	labelBox1->align(FL_ALIGN_RIGHT);
	labelBox1->labelfont(FL_HELVETICA_BOLD);
	labelBox1->labelsize(15);
	labelBox1->labelcolor(ASU_WHITE);

	labelBox2 = new Fl_Box(475, 130, 5, 20, "Team Scores by Project Priority");
	labelBox2->box(FL_FLAT_BOX);
	labelBox2->color(ASU_GREY);
	labelBox2->align(FL_ALIGN_RIGHT);
	labelBox2->labelfont(FL_HELVETICA_BOLD);
	labelBox2->labelsize(15);
	labelBox2->labelcolor(ASU_WHITE);

	labelBox3 = new Fl_Box(435, 150, 5, 15, "Low");
	labelBox3->box(FL_FLAT_BOX);
	labelBox3->color(ASU_GREY);
	labelBox3->align(FL_ALIGN_RIGHT);
	labelBox3->labelfont(FL_HELVETICA_BOLD);
	labelBox3->labelsize(12);
	labelBox3->labelcolor(ASU_BLUE);

	labelBox4 = new Fl_Box(595, 150, 5, 15, "Medium");
	labelBox4->box(FL_FLAT_BOX);
	labelBox4->color(ASU_GREY);
	labelBox4->align(FL_ALIGN_RIGHT);
	labelBox4->labelfont(FL_HELVETICA_BOLD);
	labelBox4->labelsize(12);
	labelBox4->labelcolor(ASU_ORANGE);

	labelBox5 = new Fl_Box(745, 150, 5, 15, "High");
	labelBox5->box(FL_FLAT_BOX);
	labelBox5->color(ASU_GREY);
	labelBox5->align(FL_ALIGN_RIGHT);
	labelBox5->labelfont(FL_HELVETICA_BOLD);
	labelBox5->labelsize(12);
	labelBox5->labelcolor(ASU_GOLD);

	spacer = new Fl_Box(10, 105, 840, 15, "_________________________________"
			"___________________________________________________________________________");
	spacer->box(FL_FLAT_BOX);
	spacer->color(ASU_GREY);
	spacer->align(FL_ALIGN_CENTER);
	spacer->labelfont(FL_HELVETICA_BOLD);
	spacer->labelsize(15);
	spacer->labelcolor(ASU_BLACK);

	pieChart = new Fl_Chart(20, 155, 350, 210);
	pieChart->type(FL_PIE_CHART);
	pieChart->textfont(FL_HELVETICA);
	pieChart->textcolor(ASU_BLACK);
	pieChart->textsize(14);
	pieChart->labelfont(FL_HELVETICA_BOLD);
	pieChart->labelsize(16);
	pieChart->labelcolor(ASU_WHITE);

	barChart = new Fl_Chart(395, 165, 450, 200);
	barChart->type(FL_SPIKE_CHART);

}



/* event handler for the save button. Saves file as .txt */
void ResultWindow::saveClicked(Fl_Widget *w) {
	buffer->savefile("results.csv", 1000000);
}


/* event handler for the save button. Saves file as .txt */
void ResultWindow::exitClicked(Fl_Widget *w) {
	exit(0);
}



/* method to show the results window once the buffer has been filled */
void ResultWindow::addText() {

	calculateStats();

	// Fill test box labels with data results
	char permNum[70];
	int buff = sprintf(permNum, "Number of possible permutations: %d",
			permutations);
	const char *permNum1 = permNum;
	permBox->label(permNum1);

	char swapNum[70];
	buff = sprintf(swapNum, "Number of students swapped:        %d", swaps);
	const char *swapNum1 = swapNum;
	swapBox->label(swapNum1);

	char teamNum[70];
	buff = sprintf(teamNum, "Average Team Score: %d", teamScoreAvg);
	const char *teamNum1 = teamNum;
	teamBox->label(teamNum1);

	char bestNum[70];
	buff = sprintf(bestNum, "Best Team Score: %d (Team %d)", bestScore, bestTeam);
	const char *bestNum1 = bestNum;
	bestBox->label(bestNum1);

	char badNum[70];
	buff = sprintf(badNum, "Worst Team Score: %d (Team %d)", badScore, worstTeam);
	const char *badNum1 = badNum;
	badBox->label(badNum1);


	//Fills pie charts with data results
	char low1a[50];
	buff = sprintf(low1a, " %d-%d (%d)", badScore, badScore+percent, low1);
	const char *low1b = low1a;
	pieChart->add(low1,low1b, ASU_GREEN);

	char low2a[50];
	buff = sprintf(low2a, " %d-%d (%d)", badScore+(percent)+1, badScore+(percent*2)+1, low2);
	const char *low2b = low2a;
	pieChart->add(low2, low2b, ASU_BLUE);

	char avg1a[50];
	buff = sprintf(avg1a, " %d-%d (%d)", badScore+(percent*2)+2, badScore+(percent*3)+1, avg1);
	const char *avg1b = avg1a;
	pieChart->add(avg1, avg1b, ASU_WHITE);

	char avg2a[50];
	buff = sprintf(avg2a, " %d-%d (%d)", badScore+(percent*3)+2, badScore+(percent*4)+1, avg2);
	const char *avg2b = avg2a;
	pieChart->add(avg2, avg2b, ASU_ORANGE);

	char high1a[50];
	buff = sprintf(high1a, " %d-%d (%d)", badScore+(percent*4)+2, badScore+(percent*5)+1, high1);
	const char *high1b = high1a;
	pieChart->add(high1, high1b, ASU_GOLD);

	char high2a[50];
	buff = sprintf(high2a, " %d-%d (%d)", badScore+(percent*5)+2, bestScore, high2);
	const char *high2b = high2a;
	pieChart->add(high2, high2b, ASU_MAROON);


	for(int i = 0; i < count; i ++) {
		if(project_pool[1][i] == 0 && project_pool[2][i] != 0) {
			char priob[2];
			buff = sprintf(priob, "%d", project_pool[2][i]);
			const char *prioa = priob;
			barChart->add(project_pool[2][i], prioa, ASU_BLUE);
		}
	}

	for(int i = 0; i < count; i ++) {
		if(project_pool[1][i] == 1 && project_pool[2][i] != 0) {
			char priob[2];
			buff = sprintf(priob, "%d", project_pool[2][i]);
			const char *prioa = priob;
			barChart->add(project_pool[2][i], prioa, ASU_ORANGE);
		}
	}

	for(int i = 0; i < count; i ++) {
		if(project_pool[1][i] == 2 && project_pool[2][i] != 0) {
			char priob[2];
			buff = sprintf(priob, "%d", project_pool[2][i]);
			const char *prioa = priob;
			barChart->add(project_pool[2][i], prioa, ASU_GOLD);
		}
	}


	//Show window
	windowResult->resizable(textDisplay);
	windowResult->color(ASU_GREY);
	windowResult->show();
	windowResult->end();
	Fl::run();
}


// Calculate the stats of how well the teams were formed
void ResultWindow::calculateStats() {

	//initialize variables
	teamScoreAvg = 0, bestScore = 0, badScore = 100, notAssign=0;
	int next1=0, next2=0;
	low1 =0, low2 =0, avg1 =0, avg2 =0, high1 =0, high2 =0;
	string line;


	//calculating average team score
	for(int i =  0; i < count; i ++) {
		if(project_pool[2][i] != 0) {
			teamScoreAvg += project_pool[2][i];
		} else {
			notAssign++;
		}
	}

	teamScoreAvg = teamScoreAvg/(count-notAssign);

	//calculating best team score
	for(int i =  0; i < count; i ++) {
		if(project_pool[2][i] > bestScore) {
			bestScore = project_pool[2][i];
			bestTeam = i;
		}
	}

	//calculating worst team score
	for(int i =  0; i < count; i ++) {
		if((project_pool[2][i] < badScore) && (project_pool[2][i] != 0)) {
			badScore = project_pool[2][i];
			worstTeam = i;
		}
	}

	percent = (bestScore-badScore)/6;

	//filling teams within 6 data groups for pie chart
	for(int i =  0; i < count; i ++) {
		if(project_pool[2][i] <= (badScore+percent)) { low1++;	}
		if((project_pool[2][i] <= badScore+(percent*2)) &&
			(project_pool[2][i]) > (badScore+percent)) { low2++;	}
		if((project_pool[2][i] <= badScore+(percent*3)) &&
			(project_pool[2][i]) > (badScore+percent*2)) { avg1++;	}
		if((project_pool[2][i] <= badScore+(percent*4)) &&
			(project_pool[2][i]) > (badScore+percent*3)) { avg2++;	}
		if((project_pool[2][i] <= badScore+(percent*5)) &&
			(project_pool[2][i]) > (badScore+percent*4)) { high1++;}
		if((project_pool[2][i] <= bestScore) &&
			(project_pool[2][i]) > (badScore+percent*5)) { high2++;}
	}
}


// DESTRUCTOR
ResultWindow::~ResultWindow() {
	delete windowResult;
	delete textDisplay;
	delete buffer;
	delete buttonSave;
	delete buttonExit;
	delete permBox;
	delete swapBox;
	delete borderBox;

}
