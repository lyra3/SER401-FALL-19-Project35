// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GTKMM_MENUTOOLBUTTON_H
#define _GTKMM_MENUTOOLBUTTON_H

#include <gtkmmconfig.h>


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2003 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include <gtkmm/toolbutton.h>
#include <gtkmm/menu.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMenuToolButton = struct _GtkMenuToolButton;
using GtkMenuToolButtonClass = struct _GtkMenuToolButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class MenuToolButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A Gtk::ToolItem containing a toggle button.
 *
 * A MenuToolButton is a Gtk::ToolItem that contains a menu.
 * @ingroup Widgets
 */

class MenuToolButton : public ToolButton
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef MenuToolButton CppObjectType;
  typedef MenuToolButton_Class CppClassType;
  typedef GtkMenuToolButton BaseObjectType;
  typedef GtkMenuToolButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  MenuToolButton(MenuToolButton&& src) noexcept;
  MenuToolButton& operator=(MenuToolButton&& src) noexcept;

  // noncopyable
  MenuToolButton(const MenuToolButton&) = delete;
  MenuToolButton& operator=(const MenuToolButton&) = delete;

  ~MenuToolButton() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class MenuToolButton_Class;
  static CppClassType menutoolbutton_class_;

protected:
  explicit MenuToolButton(const Glib::ConstructParams& construct_params);
  explicit MenuToolButton(GtkMenuToolButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkMenuToolButton*       gobj()       { return reinterpret_cast<GtkMenuToolButton*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkMenuToolButton* gobj() const { return reinterpret_cast<GtkMenuToolButton*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_show_menu().
  virtual void on_show_menu();


private:


public:
  /** Creates a new MenuToolButton.
   */
  MenuToolButton();

  // _WRAP_CTOR does not take a 'deprecated' parameter.
  // _WRAP_CTOR(MenuToolButton(const Gtk::StockID& stock_id), gtk_toggle_tool_button_new_from_stock)
#ifndef GTKMM_DISABLE_DEPRECATED
  /** Creates a new MenuToolButton from a StockID.
   *
   * The MenuToolButton will be created according to the @a stock_id properties.
   *
   * @param stock_id The StockID which determines the look of the MenuToolButton.
   * @deprecated Use one of the other constructors instead.
   */
   explicit MenuToolButton(const Gtk::StockID& stock_id);
   
#endif // GTKMM_DISABLE_DEPRECATED

  /** Creates a new MenuToolButton with a label.
   *
   * The MenuToolButton will have the label @a label.
   *
   * @param label The string used to display the label for this MenuToolButton.
   */
  explicit MenuToolButton(const Glib::ustring& label);

  /** Creates a new MenuToolButton with an image.
   *
   * The MenuToolButton will have the label @a label and an image widget @a icon_widget.
   *
   * @param icon_widget The widget placed as the MenuToolButton's icon.
   * @param label The string used to display the label for this MenuToolButton.
   */
  explicit MenuToolButton(Widget& icon_widget, const Glib::ustring& label = Glib::ustring());

  
  /** Sets the Gtk::Menu that is popped up when the user clicks on the arrow.
   * If @a menu is <tt>nullptr</tt>, the arrow button becomes insensitive.
   * 
   * @newin{2,6}
   * 
   * @param menu The Gtk::Menu associated with Gtk::MenuToolButton.
   */
  void set_menu(Menu& menu);
  
  /** Gets the Gtk::Menu associated with Gtk::MenuToolButton.
   * 
   * @newin{2,6}
   * 
   * @return The Gtk::Menu associated
   * with Gtk::MenuToolButton.
   */
  Menu* get_menu();
  
  /** Gets the Gtk::Menu associated with Gtk::MenuToolButton.
   * 
   * @newin{2,6}
   * 
   * @return The Gtk::Menu associated
   * with Gtk::MenuToolButton.
   */
  const Menu* get_menu() const;

  
  /** Sets the tooltip text to be used as tooltip for the arrow button which
   * pops up the menu.  See Gtk::ToolItem::set_tooltip_text() for setting a tooltip
   * on the whole Gtk::MenuToolButton.
   * 
   * @newin{2,12}
   * 
   * @param text Text to be used as tooltip text for button’s arrow button.
   */
  void set_arrow_tooltip_text(const Glib::ustring& text);
  
  /** Sets the tooltip markup text to be used as tooltip for the arrow button
   * which pops up the menu.  See Gtk::ToolItem::set_tooltip_text() for setting
   * a tooltip on the whole Gtk::MenuToolButton.
   * 
   * @newin{2,12}
   * 
   * @param markup Markup text to be used as tooltip text for button’s arrow button.
   */
  void set_arrow_tooltip_markup(const Glib::ustring& markup);

  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%show_menu()</tt>
   *
   * Flags: Run First
   *
   * The signal_show_menu() signal is emitted before the menu is shown.
   * 
   * It can be used to populate the menu on demand, using
   * Gtk::MenuToolButton::set_menu().
   * 
   * Note that even if you populate the menu dynamically in this way,
   * you must set an empty menu on the Gtk::MenuToolButton beforehand,
   * since the arrow is made insensitive if the menu is not set.
   */

  Glib::SignalProxy< void > signal_show_menu();

  /** The dropdown menu.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Menu* > property_menu() ;

/** The dropdown menu.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Menu* > property_menu() const;


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::MenuToolButton
   */
  Gtk::MenuToolButton* wrap(GtkMenuToolButton* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_MENUTOOLBUTTON_H */

