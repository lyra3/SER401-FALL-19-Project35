// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GTKMM_CELLAREA_P_H
#define _GTKMM_CELLAREA_P_H


#include <gtkmm/private/object_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class CellArea_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = CellArea;
  using BaseObjectType = GtkCellArea;
  using BaseClassType = GtkCellAreaClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class CellArea;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static GtkSizeRequestMode get_request_mode_vfunc_callback(GtkCellArea* self);
  static void get_preferred_width_vfunc_callback(GtkCellArea* self, GtkCellAreaContext* context, GtkWidget* widget, gint* minimum_width, gint* natural_width);
  static void get_preferred_height_for_width_vfunc_callback(GtkCellArea* self, GtkCellAreaContext* context, GtkWidget* widget, gint width, gint* minimum_height, gint* natural_height);
  static void get_preferred_height_vfunc_callback(GtkCellArea* self, GtkCellAreaContext* context, GtkWidget* widget, gint* minimum_height, gint* natural_height);
  static void get_preferred_width_for_height_vfunc_callback(GtkCellArea* self, GtkCellAreaContext* context, GtkWidget* widget, gint height, gint* minimum_width, gint* natural_width);
};


} // namespace Gtk


#endif /* _GTKMM_CELLAREA_P_H */

