// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GTKMM_RECENTCHOOSERDIALOG_H
#define _GTKMM_RECENTCHOOSERDIALOG_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2006 The gtkmm Development Team
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

#include <gtkmm/dialog.h>
#include <gtkmm/recentchooser.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkRecentChooserDialog = struct _GtkRecentChooserDialog;
using GtkRecentChooserDialogClass = struct _GtkRecentChooserDialogClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class RecentChooserDialog_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** RecentChooserDialog is a dialog box suitable for displaying the recently
 * used documents. This widget works by putting a RecentChooserWidget inside
 * a Dialog. It exposes the RecentChooser interface, so you can use
 * all the RecentChooser functions on the recent chooser dialog as well as
 * those for Dialog.
 *
 * Note that RecentChooserDialog does not have any methods of its own.
 * Instead, you should use the functions that work on a RecentChooser.
 *
 * A RecentChooserDialog looks like this:
 * @image html recentchooserdialog1.png
 *
 * @newin{2,10}
 *
 * @ingroup RecentFiles
 */

class RecentChooserDialog
  : public Dialog,
    public RecentChooser
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef RecentChooserDialog CppObjectType;
  typedef RecentChooserDialog_Class CppClassType;
  typedef GtkRecentChooserDialog BaseObjectType;
  typedef GtkRecentChooserDialogClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  RecentChooserDialog(RecentChooserDialog&& src) noexcept;
  RecentChooserDialog& operator=(RecentChooserDialog&& src) noexcept;

  // noncopyable
  RecentChooserDialog(const RecentChooserDialog&) = delete;
  RecentChooserDialog& operator=(const RecentChooserDialog&) = delete;

  ~RecentChooserDialog() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class RecentChooserDialog_Class;
  static CppClassType recentchooserdialog_class_;

protected:
  explicit RecentChooserDialog(const Glib::ConstructParams& construct_params);
  explicit RecentChooserDialog(GtkRecentChooserDialog* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkRecentChooserDialog*       gobj()       { return reinterpret_cast<GtkRecentChooserDialog*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkRecentChooserDialog* gobj() const { return reinterpret_cast<GtkRecentChooserDialog*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

  
public:
  
  explicit RecentChooserDialog(Gtk::Window& parent, const Glib::ustring& title);
  explicit RecentChooserDialog(const Glib::ustring& title);

  
  explicit RecentChooserDialog(Gtk::Window& parent, const Glib::ustring& title, const Glib::RefPtr<RecentManager>& recent_manager);
  explicit RecentChooserDialog(const Glib::ustring& title, const Glib::RefPtr<RecentManager>& recent_manager);


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
   * @relates Gtk::RecentChooserDialog
   */
  Gtk::RecentChooserDialog* wrap(GtkRecentChooserDialog* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_RECENTCHOOSERDIALOG_H */

