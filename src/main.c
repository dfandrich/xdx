/*  
 *  xdx - GTK+ DX-cluster client for amateur radio
 *  Copyright (C) 2002 Joop Stakenborg <pa4tu@amsat.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/*
 *  main.c - start of gtk loop.
 */

#include <gtk/gtk.h>
#include "gui.h"
#include "utils.h"
#include "preferences.h"
#include "history.h"
#include "utils.h"

int
main (int argc, char *argv[])
{
  GtkWidget *mainstatusbar, *vpaned1, *treeview;
  gchar *lang, **wsplit;
  GString *greeting = g_string_new ("");
  gint i;

  lang = gtk_set_locale ();	/* don't free lang */

#ifdef ENABLE_NLS
  bindtextdomain (PACKAGE, PACKAGE_LOCALE_DIR);
  textdomain (PACKAGE);
#endif

  add_pixmap_directory(PACKAGE_DATA_DIR G_DIR_SEPARATOR_S "pixmaps");
  add_pixmap_directory(PACKAGE_SOURCE_DIR G_DIR_SEPARATOR_S "pixmaps");

  gtk_init (&argc, &argv);

  create_mainwindow ();
  dircheck ();
  loadpreferences ();
  loadhistory ();

  gtk_widget_show (gui->window);

  treeview = g_object_get_data (G_OBJECT (gui->window), "treeview");
  wsplit = g_strsplit(preferences.columnwidths, ",", 0);
  for (i = 0; i < 5; i++)
    gtk_tree_view_column_set_fixed_width
      (gtk_tree_view_get_column(GTK_TREE_VIEW(treeview), i), atoi(wsplit[i]));
  g_strfreev(wsplit);

  gdk_window_move_resize(gui->window->window, preferences.x, preferences.y,
	preferences.width, preferences.height);
  vpaned1 = g_object_get_data (G_OBJECT (gui->window), "vpaned1");
  /* why do I have to divide the paned position by 4.25 ?? */
  gtk_paned_set_position (GTK_PANED(vpaned1), preferences.panedpos / 4.25);

  menu_set_sensitive (gui->item_factory, "/Host/Close", FALSE); /* do not translate */
  g_string_printf (greeting, _("Welcome to %s"), PACKAGE);
  updatestatusbar(greeting, FALSE);
  g_string_free (greeting, TRUE);

  gtk_main ();
  return 0;
}
