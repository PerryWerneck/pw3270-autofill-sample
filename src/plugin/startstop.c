/* SPDX-License-Identifier: LGPL-3.0-or-later */

/*
 * Copyright (C) 2021 Perry Werneck <perry.werneck@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

 #include <lib3270.h>
 #include <stdio.h>
 #include <string.h>
 #include <gtk/gtk.h>

 static void message_changed(GtkWidget *terminal, guint message) {

	g_message("Program message changed to %u",message);

 }

 /// @brief A new terminal was created, watch it
 LIB3270_EXPORT int pw3270_plugin_setup_terminal(GtkWidget *terminal) {

	// Trata mudança de nome na LU
	g_signal_connect(terminal, "message-changed", G_CALLBACK(message_changed), terminal);


	return 0;

 }


