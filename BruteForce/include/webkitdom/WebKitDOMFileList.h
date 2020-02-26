/*
 *  This file is part of the WebKit open source project.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 */

#if !defined(__WEBKITDOM_H_INSIDE__) && !defined(BUILDING_WEBKIT)
#error "Only <webkitdom/webkitdom.h> can be included directly."
#endif

#ifndef WebKitDOMFileList_h
#define WebKitDOMFileList_h

#include <glib-object.h>
#include <webkitdom/WebKitDOMObject.h>
#include <webkitdom/webkitdomdefines.h>

G_BEGIN_DECLS

#define WEBKIT_DOM_TYPE_FILE_LIST            (webkit_dom_file_list_get_type())
#define WEBKIT_DOM_FILE_LIST(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), WEBKIT_DOM_TYPE_FILE_LIST, WebKitDOMFileList))
#define WEBKIT_DOM_FILE_LIST_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass),  WEBKIT_DOM_TYPE_FILE_LIST, WebKitDOMFileListClass)
#define WEBKIT_DOM_IS_FILE_LIST(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), WEBKIT_DOM_TYPE_FILE_LIST))
#define WEBKIT_DOM_IS_FILE_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),  WEBKIT_DOM_TYPE_FILE_LIST))
#define WEBKIT_DOM_FILE_LIST_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj),  WEBKIT_DOM_TYPE_FILE_LIST, WebKitDOMFileListClass))

struct _WebKitDOMFileList {
    WebKitDOMObject parent_instance;
};

struct _WebKitDOMFileListClass {
    WebKitDOMObjectClass parent_class;
};

WEBKIT_DEPRECATED GType
webkit_dom_file_list_get_type(void);

/**
 * webkit_dom_file_list_item:
 * @self: A #WebKitDOMFileList
 * @index: A #gulong
 *
 * Returns: (transfer full): A #WebKitDOMFile
 *
 * Deprecated: 2.22: Use JavaScriptCore API instead
**/
WEBKIT_DEPRECATED WebKitDOMFile*
webkit_dom_file_list_item(WebKitDOMFileList* self, gulong index);

/**
 * webkit_dom_file_list_get_length:
 * @self: A #WebKitDOMFileList
 *
 * Returns: A #gulong
 *
 * Deprecated: 2.22: Use JavaScriptCore API instead
**/
WEBKIT_DEPRECATED gulong
webkit_dom_file_list_get_length(WebKitDOMFileList* self);

G_END_DECLS

#endif /* WebKitDOMFileList_h */
