/*
 * xdx - GTK+ DX-cluster client for amateur radio
 * Copyright (C) 2002-2003 Joop Stakenborg <pg4i@amsat.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/*
 * preferences.h
 */

#define COL0WIDTH 70
#define COL1WIDTH 70
#define COL2WIDTH 70
#define COL3WIDTH 360
#define COL4WIDTH 60
#define COL5WIDTH 60

typedef struct
{
  gint x;
  gint y;
  gint width;
  gint height;
  gchar *columnwidths;
  gint autologin;
  gchar *callsign;
  gchar *commands;
  gint savedx;
  gint savewwv;
  gint savetoall;
  gint savewx;
  gint hamlib;
  gchar *rigctl;
  gchar *browserapp;
  gchar *mailapp;
  gint col0visible;
  gint col1visible;
  gint col2visible;
  gint col3visible;
  gint col4visible;
  gint col5visible;
} preferencestype;

void dircheck (void);
void loadpreferences (void);
void savepreferences (void);
