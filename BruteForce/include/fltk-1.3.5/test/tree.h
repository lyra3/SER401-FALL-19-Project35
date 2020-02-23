// generated by Fast Light User Interface Designer (fluid) version 1.0305

#ifndef tree_h
#define tree_h
#include <FL/Fl.H>
#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Tree.H>
#include <FL/fl_ask.H>
#include <FL/fl_message.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Preferences.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Text_Display.H>
const char* reason_as_name(Fl_Tree_Reason reason);
void Button_CB(Fl_Widget*w, void*data);
void AssignUserIcons();
void RebuildTree();
Fl_Color EditColor(Fl_Color &val);
void UpdateColorChips();
int GetTreeMarginBottom();
int GetTreeWidgetMarginLeft();
Fl_Color GetSelectedItemFGColor();
Fl_Color GetSelectedItemBGColor();
#include <FL/Fl_Double_Window.H>
extern Fl_Double_Window *window;
extern Fl_Tree *tree;
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Value_Slider.H>
extern Fl_Value_Slider *margintop_slider;
extern Fl_Value_Slider *marginleft_slider;
extern Fl_Value_Slider *marginbottom_slider;
extern Fl_Value_Slider *linespacing_slider;
extern Fl_Value_Slider *usericonmarginleft_slider;
extern Fl_Value_Slider *labelmarginleft_slider;
extern Fl_Value_Slider *widgetmarginleft_slider;
extern Fl_Value_Slider *openchild_marginbottom_slider;
extern Fl_Value_Slider *connectorwidth_slider;
#include <FL/Fl_Choice.H>
extern Fl_Choice *collapseicons_chooser;
extern Fl_Choice *connectorstyle_chooser;
extern Fl_Choice *selectmode_chooser;
extern Fl_Choice *reselectmode_chooser;
extern Fl_Choice *whenmode_chooser;
#include <FL/Fl_Check_Button.H>
extern Fl_Check_Button *usericon_radio;
extern Fl_Check_Button *showroot_radio;
extern Fl_Check_Button *visiblefocus_checkbox;
extern Fl_Check_Button *labelandwidget_radio;
extern Fl_Check_Button *itemheightfromwidget_radio;
extern Fl_Box *showitem_box;
#include <FL/Fl_Button.H>
extern Fl_Button *openall_button;
extern Fl_Button *loaddb_button;
extern Fl_Button *insertabove_button;
extern Fl_Button *rebuildtree_button;
extern Fl_Button *showpathname_button;
extern Fl_Button *closeall_button;
extern Fl_Button *clearall_button;
extern Fl_Button *testcallbackflag_button;
extern Fl_Button *testrootshowself_button;
extern Fl_Button *add20k_button;
extern Fl_Choice *selected_labelfont_choice;
extern Fl_Value_Slider *selected_labelsize_slider;
extern Fl_Button *all_labelfgcolor_button;
extern Fl_Button *all_labelbgcolor_button;
#include <FL/Fl_Light_Button.H>
extern Fl_Light_Button *deactivate_items_toggle;
extern Fl_Light_Button *deactivate_tree_toggle;
extern Fl_Light_Button *bold_toggle;
extern Fl_Button *showselected_button;
extern Fl_Button *clearselected_button;
extern Fl_Button *swapselected_button;
extern Fl_Button *selectall_button;
extern Fl_Button *deselectall_button;
extern Fl_Button *nextselected_button;
extern Fl_Light_Button *bbbselect_toggle;
extern Fl_Light_Button *bbbselect2_toggle;
extern Fl_Light_Button *bbbchild02select_toggle;
extern Fl_Light_Button *rootselect_toggle;
extern Fl_Light_Button *rootselect2_toggle;
extern Fl_Choice *labelfont_choice;
extern Fl_Value_Slider *labelsize_slider;
extern Fl_Choice *item_labelfont_choice;
extern Fl_Value_Slider *item_labelsize_slider;
extern Fl_Button *labelcolor_button;
extern Fl_Button *color_button;
extern Fl_Button *selection_color_button;
extern Fl_Button *item_labelfgcolor_button;
extern Fl_Button *item_labelbgcolor_button;
extern Fl_Button *x_item_labelbgcolor_button;
extern Fl_Button *testsuggs_button;
extern Fl_Value_Slider *tree_scrollbar_size_slider;
extern Fl_Value_Slider *scrollbar_size_slider;
extern Fl_Box *resizer_box;
extern Fl_Menu_Item menu_collapseicons_chooser[];
extern Fl_Menu_Item menu_connectorstyle_chooser[];
extern Fl_Menu_Item menu_selectmode_chooser[];
extern Fl_Menu_Item menu_reselectmode_chooser[];
extern Fl_Menu_Item menu_whenmode_chooser[];
extern Fl_Menu_Item menu_selected_labelfont_choice[];
extern Fl_Menu_Item menu_labelfont_choice[];
extern Fl_Menu_Item menu_item_labelfont_choice[];
#endif
