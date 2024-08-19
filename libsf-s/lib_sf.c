/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_sf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:03:22 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/08/02 16:03:28 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libsf.h"

// Function to create a simple window
Tool*	create_window_s(const char *title, int width, int height)
{
	Tool *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), title);
	gtk_window_set_default_size(GTK_WINDOW(window), width, height);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	return (window);
}

Tool*	create_window_p(const char *title, int width, int height, gboolean resizable)
{
	Tool *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), title);
	gtk_window_set_default_size(GTK_WINDOW(window), width, height);
	gtk_window_set_resizable(GTK_WINDOW(window), resizable);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	window_center(window, 880, 580);
	return (window);
}

void	sf_icon(GtkApplication *app, const char *icon_path)
{
	GdkPixbuf *icon;

	if (app != NULL && icon_path != NULL)
	{
		icon = gdk_pixbuf_new_from_file(icon_path, NULL);
		if (icon != NULL)
		{
			GtkWindow *window;

			window = GTK_WINDOW(gtk_application_get_active_window(app));
			if (window != NULL)
			{
				gtk_window_set_icon(window, icon);
			}
			g_object_unref(icon);
		}
	}
}
// Função para criar uma janela com a opção de tamanho fixo ou redimensionável
Tool*	create_window(const char *title, int width, int height, gboolean resizable)
{
	Tool *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), title);
	gtk_window_set_default_size(GTK_WINDOW(window), width, height);
	gtk_window_set_resizable(GTK_WINDOW(window), resizable);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	return window;
}


// Funcao para criar conteiner fixo
Tool*	fixed_layout_window(Tool *window)
{
	Tool *fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);
	return (fixed);
}

// Function to add a button to a container
Tool*	add_button(Tool *fixed, const char *button_text, int x, int y, BCall callback, Pont data)
{
	GtkWidget *button = gtk_button_new_with_label(button_text);
	gtk_fixed_put(GTK_FIXED(fixed), button, x, y);
	gtk_widget_set_size_request(button, 100, 30);
	if (callback)
		g_signal_connect(button, "clicked", G_CALLBACK(callback), data);
	gtk_widget_show(button);
	return (button);
}

// Function to add a label to a container
Tool*	add_label(Tool *container, const char *text, int x, int y)
{
	Tool *label = gtk_label_new(text);
	gtk_fixed_put(GTK_FIXED(container), label, x, y);
	return (label);
}

// Function to add an entry widget to a container
char	*if_event(int event)
{
	if (event == 1)
		return ("changed");
	else if (event == 2)
		return ("focus-in-event");
	else if (event == 3)
		return ("focus-out-event");
	else if (event == 4)
		return ("button-press-event");
	else if (event == 5)
		return ("button-release-event");
	else if (event == 6)
		return ("key-press-event");
	else if (event == 7)
		return ("key-release-event");
	else if (event == 8)
		return ("enter-notify-event");
	else if (event == 9)
		return ("leave-notify-event");
	else if (event == 10)
		return ("motion-notify-event");
	else if (event == 11)
		return ("delete-event");
	else if (event == 12)
		return ("destroy-event");
	else if (event == 13)
		return ("expose-event");
	else if (event == 14)
		return ("map-event");
	else if (event == 15)
		return ("unmap-event");
	else if (event == 16)
		return ("property-notify-event");
	else if (event == 17)
		return ("selection-clear-event");
	else if (event == 18)
		return ("selection-request-event");
	else if (event == 19)
		return ("selection-notify-event");
	else if (event == 20)
		return ("proximity-in-event");
	else if (event == 21)
		return ("proximity-out-event");
	else if (event == 22)
		return ("scroll-event");
	else if (event == 23)
		return ("visibility-notify-event");
	else if (event == 24)
		return ("window-state-event");
	else if (event == 25)
		return ("configure-event");
	else if (event == 26)
		return ("grab-broken-event");
	else if (event == 27)
		return ("drag-begin-event");
	else if (event == 28)
		return ("drag-end-event");
	else if (event == 29)
		return ("drag-motion-event");
	else if (event == 30)
		return ("drag-drop-event");
	else if (event == 31)
		return ("drag-leave-event");
	else if (event == 32)
		return ("drag-data-received-event");
	else if (event == 33)
		return ("drag-data-delete-event");
	else if (event == 34)
		return ("drag-failed-event");
	else if (event == 35)
		return ("client-event");
	else if (event == 36)
		return ("selection-toggled-event");
	else if (event == 37)
		return ("scroll-child-event");
	else if (event == 38)
		return ("touch-event");
	else if (event == 39)
		return ("touch-begin-event");
	else if (event == 40)
		return ("touch-update-event");
	else if (event == 41)
		return ("touch-end-event");
	else if (event == 42)
		return ("touch-cancel-event");
	else if (event == 43)
		return ("screen-changed-event");
	else if (event == 44)
		return ("size-allocate-event");
	else if (event == 45)
		return ("state-changed-event");
	else if (event == 46)
		return ("keymap-changed-event");
	else if (event == 47)
		return ("popup-menu-event");
	else if (event == 48)
		return ("panning-event");
	else if (event == 49)
		return ("draw-event");
	else if (event == 50)
		return ("button-drag-event");
	else if (event == 51)
		return ("clicked");
	else if (event == 52)
		return "double-clicked";
	else if (event == 53)
		return "right-clicked";
	else if (event == 54)
		return "middle-clicked";
	else if (event == 55)
		return "hovered";
	else if (event == 56)
		return "pressed";
	else if (event == 57)
		return "released";
	else if (event == 58)
		return "dragged";
	else if (event == 59)
		return "focused";
	else if (event == 60)
		return "blurred";
	return ("activate");
}



Tool*	add_EText(Tool *container, int x, int y, int event, ECall callback, Pont data)
{
	Tool *entry = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(container), entry, x, y);
	const char *signal_name = if_event(event);
	if (signal_name)
		g_signal_connect(entry, signal_name, G_CALLBACK(callback), data);

	return (entry);
}

void	set_EText(GtkWidget *entry, char *str)
{
	gtk_entry_set_text(GTK_ENTRY(entry), str);
}
String	get_EText(GtkWidget *entry)
{
	return ((String)gtk_entry_get_text(GTK_ENTRY(entry)));
}

// Function to add a color chooser to a container
Tool	*add_color_chooser(Tool *container, int x, int y, GCallback callback)
{
	Tool *color_chooser = gtk_color_button_new();
	gtk_fixed_put(GTK_FIXED(container), color_chooser, x, y);
	g_signal_connect(color_chooser, "color-set", callback, NULL);
	return (color_chooser);
}

// Function to add a drawing area to a container
Tool	*add_drawing_area(Tool *container, int x, int y, int width, int height, GCallback draw_callback)
{
	Tool *drawing_area = gtk_drawing_area_new();
	gtk_widget_set_size_request(drawing_area, width, height);
	gtk_fixed_put(GTK_FIXED(container), drawing_area, x, y);
	g_signal_connect(drawing_area, "draw", draw_callback, NULL);
	return (drawing_area);
}

// Function to add a file chooser button to a container
Tool	*add_file_chooser(Tool *container, int x, int y, GCallback callback)
{
	Tool *file_chooser = gtk_file_chooser_button_new("Choose a file", GTK_FILE_CHOOSER_ACTION_OPEN);
	gtk_fixed_put(GTK_FIXED(container), file_chooser, x, y);
	g_signal_connect(file_chooser, "file-set", callback, NULL);
	return (file_chooser);
}

// Function to add an image to a container
Tool	*add_image(Tool *container, const char *file_path, int x, int y)
{
	Tool *image = gtk_image_new_from_file(file_path);
	gtk_fixed_put(GTK_FIXED(container), image, x, y);
	return (image);
}

// Function to add a separator to a container
Tool	*add_separator(Tool *container, int x, int y, gboolean horizontal)
{
	Tool *separator;
	if (horizontal)
		separator = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
	else
		separator = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
	gtk_fixed_put(GTK_FIXED(container), separator, x, y);
	return (separator);
}

// Function to add tabs to a notebook
void	add_tabs(Tool *notebook, Tool **pages, const char **titles, int count)
{
	for (int i = 0; i < count; i++)
		gtk_notebook_append_page(GTK_NOTEBOOK(notebook), pages[i], gtk_label_new(titles[i]));
}

// Function to add a volume slider to a container
Tool	*add_volume_slider(Tool *container, int x, int y, GCallback callback)
{
	Tool *scale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
	gtk_fixed_put(GTK_FIXED(container), scale, x, y);
	g_signal_connect(scale, "value-changed", F(callback), NULL);
	return scale;
}

// Function to add a checkbox to a container
Tool	*add_checkbox(Tool *container, const char *label, int x, int y, GCallback callback)
{
	Tool *checkbox = gtk_check_button_new_with_label(label);
	gtk_fixed_put(GTK_FIXED(container), checkbox, x, y);
	g_signal_connect(checkbox, "toggled", F(callback), NULL);
	return (checkbox);
}

// Function to add a radio button to a container
Tool	*add_radio_button(Tool *container, Tool
		*group, const char *label, int x, int y)
{
	Tool *radio_button = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(group), label);
	gtk_fixed_put(GTK_FIXED(container), radio_button, x, y);
	return (radio_button);
}

// Function to add a combo box to a container
Tool	*add_combo_box(Tool *container, int x, int y,
		gchar **items, int item_count, GCallback callback)
{
	Tool *combo_box = gtk_combo_box_text_new();
	for (int i = 0; i < item_count; i++)
	{
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), items[i]);
	}
	gtk_fixed_put(GTK_FIXED(container), combo_box, x, y);
	g_signal_connect(combo_box, "changed", callback, NULL);
	return (combo_box);
}

// Function to add a calendar to a container
Tool	*add_calendar(Tool *container, int x, int y, GCallback callback)
{
	Tool *calendar = gtk_calendar_new();
	gtk_fixed_put(GTK_FIXED(container), calendar, x, y);
	g_signal_connect(calendar, "day-selected", callback, NULL);
	return (calendar);
}

// Function to add a status bar to a container
Tool	*add_status_bar(Tool *container, int x, int y)
{
	Tool *status_bar = gtk_statusbar_new();
	gtk_fixed_put(GTK_FIXED(container), status_bar, x, y);
	return (status_bar);
}

// Function to add a context menu to a widget
Tool	*add_context_menu(Tool *widget, Tool *menu)
{
	g_signal_connect(widget, "button-press-event", G_CALLBACK(gtk_menu_popup_at_pointer), menu);
	return (menu);
}

// Function to add a toolbar with buttons to a container
Tool	*add_toolbar_with_buttons(Tool *container,
				const char **button_labels, int count)
{
	Tool *toolbar = gtk_toolbar_new();
	for (int i = 0; i < count; i++)
	{
		GtkToolItem *button = gtk_tool_button_new(NULL, button_labels[i]);
		gtk_toolbar_insert(GTK_TOOLBAR(toolbar), button, -1);
	}
	gtk_box_pack_start(GTK_BOX(container), toolbar, FALSE, FALSE, 0);
	return (toolbar);
}

// Function to add a spinner to a container
Tool	*add_spinner(Tool *container, int x, int y)
{
	Tool *spinner = gtk_spinner_new();
	gtk_fixed_put(GTK_FIXED(container), spinner, x, y);
	return (spinner);
}

// Function to add a text view to a container
Tool	*add_text_view(Tool *container, int x, int y, int width, int height)
{
	Tool *text_view = gtk_text_view_new();
	gtk_widget_set_size_request(text_view, width, height);
	gtk_fixed_put(GTK_FIXED(container), text_view, x, y);
	return (text_view);
}

// Function to create an image with specified position and size
Tool	*create_image_with_position(Tool *container, const char
		*file_path, int x, int y, int width, int height)
{
	Tool *image = gtk_image_new_from_file(file_path);
	gtk_widget_set_size_request(image, width, height);
	gtk_fixed_put(GTK_FIXED(container), image, x, y);
	return (image);
}

// Function to create a scale widget with specified position
Tool	*create_scale_with_position(Tool *container,
				int x, int y, int min, int max, int step)
{
	Tool *scale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, min, max, step);
	gtk_fixed_put(GTK_FIXED(container), scale, x, y);
	return (scale);
}

// Function to create a checkbox with specified position
Tool	*create_checkbox_with_position(Tool *container,
				const char *label, int x, int y, gboolean active)
{
	Tool *checkbox = gtk_check_button_new_with_label(label);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbox), active);
	gtk_fixed_put(GTK_FIXED(container), checkbox, x, y);
	return (checkbox);
}

// Function to create a drawing area with specified position and size
Tool	*create_drawing_area_with_position(Tool *container, int x, int y,
		int width, int height, gboolean (*draw_callback)(Tool *, cairo_t *, gpointer), gpointer data)
{
	Tool *drawing_area = gtk_drawing_area_new();
	gtk_widget_set_size_request(drawing_area, width, height);
	gtk_fixed_put(GTK_FIXED(container), drawing_area, x, y);
	g_signal_connect(drawing_area, "draw", G_CALLBACK(draw_callback), data);
	return (drawing_area);
}

// Function to create a label with specified position and color
Tool *create_label_with_position(Tool *container, const char *text,
					int x, int y, const GdkRGBA *color)
{
	Tool *label = gtk_label_new(text);
	gtk_widget_override_color(label, GTK_STATE_FLAG_NORMAL, color);
	gtk_fixed_put(GTK_FIXED(container), label, x, y);
	return (label);
}

// Function to create a button with specified position
Tool	*create_button_with_position(Tool *container, const char *label, int x, int y, void (*callback)(Tool *, gpointer), gpointer data)
{
	Tool *button = gtk_button_new_with_label(label);
	gtk_fixed_put(GTK_FIXED(container), button, x, y);
	g_signal_connect(button, "clicked", G_CALLBACK(callback), data);
	return (button);
}

// Function to create a check button
Tool	*create_check_button(const char *label, gboolean initial_state)
{
	Tool *check_button = gtk_check_button_new_with_label(label);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check_button), initial_state);
	return (check_button);
}

// Function to create a progress bar
Tool	*create_progress_bar(double initial_fraction)
{
	Tool *progress_bar = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), initial_fraction);
	return (progress_bar);
}

// Function to create a spin button
Tool	*create_spin_button(double min, double max, double step, double initial_value)
{
	Tool *spin_button = gtk_spin_button_new_with_range(min, max, step);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_button), initial_value);
	return (spin_button);
}

// Function to create a combo box
Tool	*create_combo_box(const char **items, int num_items, int default_index)
{
	Tool *combo_box = gtk_combo_box_text_new();
	for (int i = 0; i < num_items; i++)
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), items[i]);
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo_box), default_index);
	return (combo_box);
}

// Function to create an image placeholder
Tool	*create_image_ph(Tool *container,
			const char *file_path, gint x, gint y, gint width, gint height)
{
	Tool *image = gtk_image_new_from_file(file_path);
	gtk_widget_set_size_request(image, width, height);
	gtk_fixed_put(GTK_FIXED(container), image, x, y);
	return (image);
}

// Function to create a vertical box
Tool	*create_vbox(gboolean homogeneous, gint spacing)
{
	return (gtk_box_new(GTK_ORIENTATION_VERTICAL, spacing));
}

// Function to create a horizontal box
Tool	*create_hbox(gboolean homogeneous, gint spacing)
{
	return (gtk_box_new(GTK_ORIENTATION_HORIZONTAL, spacing));
}

// Function to create a grid
Tool	*create_grid(gint row_spacing, gint column_spacing)
{
	Tool *grid = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(grid), row_spacing);
	gtk_grid_set_column_spacing(GTK_GRID(grid), column_spacing);
	return (grid);
}

// Function to create a fixed layout
Tool	*create_fixed_layout(void)
{
	return (gtk_fixed_new());
}

// Function to create an entry with a border color
Tool	*create_entry1(GtkFixed *fixed, gint x, gint y,
			const char *border_color, void (*callback)(GtkEntry *, gpointer))
{
	Tool *entry = gtk_entry_new();
	gtk_fixed_put(fixed, entry, x, y);
	g_signal_connect(entry, "activate", G_CALLBACK(callback), NULL);
	// Apply border color (this requires CSS in GTK 3)
	char css[256];
	snprintf(css, sizeof(css), "entry { border: 1px solid %s; }", border_color);
	apply_css(entry, css);
	return (entry);
}

// Function to create a label
Tool	*create_label(Tool *container, const char *text)
{
	Tool *label = gtk_label_new(text);
	gtk_container_add(GTK_CONTAINER(container), label);
	return (label);
}

// Function to create a text view
Tool	*create_text_view(Tool *container)
{
	Tool *text_view = gtk_text_view_new();
	gtk_container_add(GTK_CONTAINER(container), text_view);
	return (text_view);
}

// Function to run the GTK main loop
void	loop_window(Tool *window)
{
	gtk_widget_show_all(window);
	gtk_main();
}

// Function to add an event to a widget
void	add_event(Tool *widget, const char *event_name, GCallback callback)
{
	g_signal_connect(widget, event_name, callback, NULL);
}

// Function to add a widget to a fixed container
void	add_to_fixed(GtkFixed *fixed, Tool *widget, gint x, gint y)
{
	gtk_fixed_put(fixed, widget, x, y);
}

// Function to add a widget to a grid
void	add_to_grid(GtkGrid *grid, Tool *widget,
			guint left, guint top, guint width, guint height)
{
	gtk_grid_attach(GTK_GRID(grid), widget, left, top, width, height);
}

// Function to create a new window
Tool	*new_window(const char *title, int width, int height)
{
	return (create_window_s(title, width, height));
}

// Function to apply CSS to a widget
void apply_css(Tool *widget, const char *css)
{
	GtkCssProvider *provider = gtk_css_provider_new();
	gtk_css_provider_load_from_data(provider, css, -1, NULL);
	GtkStyleContext *context = gtk_widget_get_style_context(widget);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	g_object_unref(provider);
}

// Function to set button color
void	set_button_color(Tool *button, const char *color)
{
	char css[256];
	snprintf(css, sizeof(css), "button { background-color: %s; }", color);
	apply_css(button, css);
}

// Function to set label color
void	set_label_color(Tool *label, const char *color)
{
	char css[256];
	snprintf(css, sizeof(css), "label { color: %s; }", color);
	apply_css(label, css);
}

// Function to set entry border color
void	set_entry_border_color(Tool *entry, const char *color)
{
	char css[256];
	snprintf(css, sizeof(css), "entry { border: 1px solid %s; }", color);
	apply_css(entry, css);
}

GtkFixed* initialize_layout(Tool *window)
{
    GtkFixed *fixed = GTK_FIXED(gtk_fixed_new());
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(fixed));
    return fixed;
}

// Function to create an image
Tool*	create_image(GtkFixed *fixed, const char *file_path, gint x, gint y)
{
	Tool *image = gtk_image_new_from_file(file_path);
	gtk_fixed_put(fixed, image, x, y);
	return (image);
}

// Function to create an entry
Tool*	create_entry(GtkFixed *fixed, gint x, gint y)
{
	Tool *entry = gtk_entry_new();
	gtk_fixed_put(fixed, entry, x, y);
	return (entry);
}

// Function to create text
Tool*	create_text(GtkFixed *fixed, const char *text, gint x, gint y)
{
	Tool *label = gtk_label_new(text);
	gtk_fixed_put(fixed, label, x, y);
	return (label);
}

// Function to create a button
Tool*	create_button(GtkFixed *fixed, const char *label, gint x, gint y,
		void (*callback)(Tool *, gpointer), gpointer user_data)
{
	Tool *button = gtk_button_new_with_label(label);
	gtk_fixed_put(fixed, button, x, y);
	g_signal_connect(button, "clicked", G_CALLBACK(callback), user_data);
	return (button);
}

// Function to show a notification
void	show_notification(Tool *parent, const char *title, const char *message)
{
	Tool *dialog = gtk_message_dialog_new(GTK_WINDOW(parent),
	GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", message);
	gtk_window_set_title(GTK_WINDOW(dialog), title);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

// Function to set a mouse event handler
void	set_mouse_event_handler(Tool *widget,
		void (*handler)(GdkEventButton *, gpointer), gpointer user_data)
{
	t_mouse_event_data *event_data = g_new(t_mouse_event_data, 1);
	event_data->mouse_handler = handler;
	event_data->user_data = user_data;
	g_signal_connect(widget, "button-press-event", G_CALLBACK(handler), event_data);
}

// Function to set a key event handler
void	set_key_event_handler(Tool *widget,
		void (*handler)(GdkEventKey *, gpointer), gpointer user_data)
{
	t_key_event_data *event_data = g_new(t_key_event_data, 1);
	event_data->key_handler = handler;
	event_data->user_data = user_data;
	g_signal_connect(widget, "key-press-event", G_CALLBACK(handler), event_data);
}

// Function to set a loop event handler
void	set_loop_event_handler(guint interval,
		void (*handler)(gpointer), gpointer user_data)
{
	t_loop_event_data *event_data = g_new(t_loop_event_data, 1);
	event_data->loop_handler = handler;
	event_data->user_data = user_data;
	g_timeout_add(interval, (GSourceFunc)handler, event_data);
}

// Function to create an image with a container
Tool	*create_image_c(Tool *container, const char *file_path)
{
	Tool *image = gtk_image_new_from_file(file_path);
	gtk_container_add(GTK_CONTAINER(container), image);
	return (image);
}

// Function to create a calendar
Tool	*create_calendar(Tool *container)
{
	Tool *calendar = gtk_calendar_new();
	gtk_container_add(GTK_CONTAINER(container), calendar);
	return (calendar);
}

// Function to create a file chooser button
Tool	*create_file_chooser_button(Tool *container, const char *title,
		GtkFileChooserAction action, GCallback callback, gpointer data)
{
	Tool *file_chooser = gtk_file_chooser_button_new(title, action);
	g_signal_connect(file_chooser, "file-set", callback, data);
	gtk_container_add(GTK_CONTAINER(container), file_chooser);
	return (file_chooser);
}

// Function to create a color chooser
Tool	*create_color_chooser(Tool *container,
				GCallback callback, gpointer data)
{
	Tool *color_chooser = gtk_color_chooser_widget_new();
	g_signal_connect(color_chooser, "color-activated", callback, data);
	gtk_container_add(GTK_CONTAINER(container), color_chooser);
	return (color_chooser);
}

// Function to create a notebook
Tool	*create_notebook(Tool *container)
{
	Tool *notebook = gtk_notebook_new();
	gtk_container_add(GTK_CONTAINER(container), notebook);
	return (notebook);
}

// Function to add a tab to a notebook
void	add_tab_to_notebook(Tool *notebook, const char *label, Tool *content)
{
	gtk_notebook_append_page(GTK_NOTEBOOK(notebook), content, gtk_label_new(label));
}

// Function to create a media viewer
Tool	*create_media_viewer(Tool *container)
{
	// Assuming you have your own implementation
	return NULL;
}

// Function to set a status bar message
void	set_status_bar_message(Tool *status_bar, const char *message)
{
	guint context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(status_bar), "example");
	gtk_statusbar_push(GTK_STATUSBAR(status_bar), context_id, message);
}

// Function to create a toolbar
Tool	*create_toolbar(Tool *container)
{
	Tool *toolbar = gtk_toolbar_new();
	gtk_container_add(GTK_CONTAINER(container), toolbar);
	return (toolbar);
}

// Function to create a toolbar button
GtkToolItem	*create_toolbar_button(Tool *toolbar, const char *icon_name,
				const char *tooltip, GCallback callback, gpointer data)
{
	GtkToolItem *button = gtk_tool_button_new(NULL, tooltip);
	gtk_tool_item_set_tooltip_text(button, tooltip);
	g_signal_connect(button, "clicked", callback, data);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), button, -1);
	return (button);
}

// Function to add a widget at a specific position in a fixed container
Tool	*add_widget_at_position(Tool *fixed_container,
				Tool *widget, int x, int y)
{
	gtk_fixed_put(GTK_FIXED(fixed_container), widget, x, y);
	return (widget);
}

// Function to create an info dialog
Tool	*create_info_dialog(GtkWindow *parent,
				const char *title, const char *message)
{
	Tool *dialog = gtk_message_dialog_new(parent, GTK_DIALOG_DESTROY_WITH_PARENT,
	GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", message);
	gtk_window_set_title(GTK_WINDOW(dialog), title);
	return (dialog);
}

// Function to create a warning dialog
Tool	*create_warning_dialog(GtkWindow *parent, const char *title, const char *message)
{
	Tool *dialog = gtk_message_dialog_new(parent, GTK_DIALOG_DESTROY_WITH_PARENT,
	GTK_MESSAGE_WARNING, GTK_BUTTONS_OK, "%s", message);
	gtk_window_set_title(GTK_WINDOW(dialog), title);
	return (dialog);
}

// Function to create a question dialog
Tool	*create_question_dialog(GtkWindow *parent,
					const char *title, const char *question)
{
	Tool *dialog = gtk_message_dialog_new(parent, GTK_DIALOG_DESTROY_WITH_PARENT,
	GTK_MESSAGE_QUESTION, GTK_BUTTONS_YES_NO, "%s", question);
	gtk_window_set_title(GTK_WINDOW(dialog), title);
	return (dialog);
}

// Function to create a file chooser dialog
Tool	*create_file_chooser_dialog(GtkWindow *parent,
				const char *title, GtkFileChooserAction action)
{
	Tool *dialog = gtk_file_chooser_dialog_new(title, parent, action, "_Cancel",
	GTK_RESPONSE_CANCEL, "_Open", GTK_RESPONSE_ACCEPT, NULL);
	return (dialog);
}

// Function to set a widget's size request
void	set_widget_size(Tool *widget, int width, int height)
{
	gtk_widget_set_size_request(widget, width, height);
}

// Function to create a menu item
Tool	*create_menu_item(const char *label, GCallback callback, gpointer data)
{
	Tool *menu_item = gtk_menu_item_new_with_label(label);
	g_signal_connect(menu_item, "activate", callback, data);
	return (menu_item);
}

// Function to create a menu bar
Tool	*create_menu_bar(void)
{
	return (gtk_menu_bar_new());
}

// Function to add a menu item to a menu
void	add_menu_item(Tool *menu, const char *label, GCallback callback, gpointer data)
{
	Tool *menu_item = gtk_menu_item_new_with_label(label);
	g_signal_connect(menu_item, "activate", callback, data);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
}

// Function to create a menu
Tool	*create_menu(void) {
	return (gtk_menu_new());
}

// Function to add a submenu to a menu item
void	add_submenu(Tool *menu_item, Tool *submenu)
{
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), submenu);
}

// Function to create a scrollable window
Tool	*create_scrollable_window(Tool *child, int width, int height)
{
	Tool *scrollable_window = gtk_scrolled_window_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER(scrollable_window), child);
	gtk_widget_set_size_request(scrollable_window, width, height);
	return (scrollable_window);
}

// Function to create a color button
Tool	*create_color_button(const GdkRGBA *color, GCallback callback, gpointer data)
{
	Tool *color_button = gtk_color_button_new_with_rgba(color);
	g_signal_connect(color_button, "color-set", callback, data);
	return (color_button);
}

// Function to create a file filter
GtkFileFilter	*create_file_filter(const char *name, const char **patterns)
{
	GtkFileFilter *filter = gtk_file_filter_new();
	gtk_file_filter_set_name(filter, name);
	while (*patterns)
		gtk_file_filter_add_pattern(filter, *patterns++);
	return (filter);
}

// Function to create a tree view
Tool	*create_tree_view(GtkListStore *store)
{
	Tool *tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
	g_object_unref(store);
	return (tree_view);
}

// Function to create a list store
GtkListStore	*create_list_store(GType *types, int n_columns)
{
	return (gtk_list_store_newv(n_columns, types));
}

// Function to create a cell renderer
GtkCellRenderer	*create_cell_renderer(void)
{
	return (gtk_cell_renderer_text_new());
}

// Function to add a column to a tree view
void	add_column_to_tree_view(Tool *tree_view, const char *title,
			GtkCellRenderer *renderer, int column_id)
{
	GtkTreeViewColumn *column = gtk_tree_view_column_new_with_attributes(title,
		renderer, "text", column_id, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
}

// Function to create a list view
Tool	*create_list_view(GtkListStore *store, GType *types, int n_columns)
{
	Tool *list_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
	g_object_unref(store);
	for (int i = 0; i < n_columns; i++)
	{
		GtkCellRenderer *renderer = create_cell_renderer();
		GtkTreeViewColumn *column = gtk_tree_view_column_new_with_attributes("", renderer,
									"text", i, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list_view), column);
	}
	return (list_view);
}

// Function to add a row to a list store
/*void add_row_to_list_store(GtkListStore *store, ...) {
    GtkTreeIter iter;
    va_list args;
    va_start(args, store);
    gtk_list_store_append(store, &iter);
    for (int i = 0; i < G_N_ELEMENTS(store->priv->columns); i++) {
        GValue value = G_VALUE_INIT;
        g_value_init(&value, store->priv->columns[i]);
        g_value_set_string(&value, va_arg(args, char *));
        gtk_list_store_set_value(store, &iter, i, &value);
        g_value_unset(&value);
    }
    va_end(args);
}
*/
// Function to create a text buffer
GtkTextBuffer	*create_text_buffer(const char *text)
{
	GtkTextBuffer *buffer = gtk_text_buffer_new(NULL);
	gtk_text_buffer_set_text(buffer, text, -1);
	return (buffer);
}

// Function to set text in a text view
void	set_text_view_text(Tool *text_view, const char *text)
{
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
	gtk_text_buffer_set_text(buffer, text, -1);
}

// Function to get text from a text view
char	*get_text_view_text(Tool *text_view)
{
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
	GtkTextIter start, end;
	gtk_text_buffer_get_bounds(buffer, &start, &end);
	return (gtk_text_buffer_get_text(buffer, &start, &end, FALSE));
}

// Function to create a link button
Tool	*create_link_button(const char *uri, const char *label)
{
	return (gtk_link_button_new_with_label(uri, label));
}

// Function to create a toggle button
Tool	*create_toggle_button(const char *label, gboolean initial_state)
{
	Tool *toggle_button = gtk_toggle_button_new_with_label(label);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_button), initial_state);
	return (toggle_button);
}

// Function to create a radio button
Tool	*create_radio_button(Tool *group, const char *label, gboolean active)
{
	Tool *radio_button = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(group), label);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio_button), active);
	return (radio_button);
}

// Function to create a status icon
GtkStatusIcon	*create_status_icon(const char *icon_name, const char *tooltip)
{
	GtkStatusIcon *status_icon = gtk_status_icon_new_from_icon_name(icon_name);
	gtk_status_icon_set_tooltip_text(status_icon, tooltip);
	return (status_icon);
}

// Function to set the status icon's tooltip
/*void set_status_icon_tooltip(GtkStatusIcon *status_icon, const char *tooltip) {
    gtk_status_icon_set_tooltip_text(status_icon, tooltip);
}*/

// Function to create a scale
Tool	*create_scale(GtkOrientation orientation, double min, double max, double step)
{
	return (gtk_scale_new_with_range(orientation, min, max, step));
}

// Function to set the scale's value
void	set_scale_value(Tool *scale, double value)
{
	gtk_range_set_value(GTK_RANGE(scale), value);
}

// Function to get the scale's value
double	get_scale_value(Tool *scale)
{
	return (gtk_range_get_value(GTK_RANGE(scale)));
}

// Function to create a scrollbar
Tool	*create_scrollbar(GtkOrientation orientation, GtkAdjustment *adjustment)
{
	return (gtk_scrollbar_new(orientation, adjustment));
}

// Function to set the scrollbar's value
void	set_scrollbar_value(Tool *scrollbar, double value)
{
	gtk_adjustment_set_value(gtk_range_get_adjustment(GTK_RANGE(scrollbar)), value);
}

// Function to get the scrollbar's value
double	get_scrollbar_value(Tool *scrollbar)
{
	return (gtk_adjustment_get_value(gtk_range_get_adjustment(GTK_RANGE(scrollbar))));
}

// Function to create an icon view
Tool	*create_icon_view(GtkListStore *store)
{
	Tool *icon_view = gtk_icon_view_new_with_model(GTK_TREE_MODEL(store));
	g_object_unref(store);
	return (icon_view);
}

// Function to add a column to an icon view
void	add_column_to_icon_view(Tool *icon_view, int column_id)
{
	gtk_icon_view_set_text_column(GTK_ICON_VIEW(icon_view), column_id);
}

// Function to create a paned window
Tool	*create_paned(GtkOrientation orientation)
{
	return (gtk_paned_new(orientation));
}

// Function to pack widgets into a paned window
void	pack_into_paned(Tool *paned, Tool *child1,
			Tool *child2, gboolean resize1, gboolean resize2)
{
	gtk_paned_pack1(GTK_PANED(paned), child1, resize1, TRUE);
	gtk_paned_pack2(GTK_PANED(paned), child2, resize2, TRUE);
}

// Function to set a widget's sensitive state
void	set_widget_sensitive(Tool *widget, gboolean sensitive)
{
	gtk_widget_set_sensitive(widget, sensitive);
}

// Function to create a spinner
Tool	*create_spinner(void)
{
	return (gtk_spinner_new());
}

// Function to start a spinner
void	start_spinner(Tool *spinner)
{
	gtk_spinner_start(GTK_SPINNER(spinner));
}

// Function to stop a spinner
void	stop_spinner(Tool *spinner)
{
 	gtk_spinner_stop(GTK_SPINNER(spinner));
}

// Function to create an about dialog
Tool	*create_about_dialog(GtkWindow *parent,
			const char *program_name, const char *version, const char *comments)
{
	Tool *dialog = gtk_about_dialog_new();
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(dialog), program_name);
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), version);
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), comments);
	gtk_window_set_transient_for(GTK_WINDOW(dialog), parent);
	return (dialog);
}

// Function to create an overlay
Tool	*create_overlay(Tool *container)
{
	Tool *overlay = gtk_overlay_new();
	gtk_container_add(GTK_CONTAINER(container), overlay);
	return (overlay);
}

// Function to add a widget to an overlay
void	add_to_overlay(Tool *overlay, Tool *widget)
{
	gtk_overlay_add_overlay(GTK_OVERLAY(overlay), widget);
}

// Function to create a separator
Tool	*create_separator(GtkOrientation orientation)
{
	return (gtk_separator_new(orientation));
}

// Function to create an expander
Tool	*create_expander(const char *label)
{
	return (gtk_expander_new(label));
}

// Function to set the expander's expanded state
void	set_expander_expanded(Tool *expander, gboolean expanded)
{
	gtk_expander_set_expanded(GTK_EXPANDER(expander), expanded);
}

// Function to get the expander's expanded state
gboolean	get_expander_expanded(Tool *expander)
{
	return (gtk_expander_get_expanded(GTK_EXPANDER(expander)));
}

// Function to create a search entry
Tool	*create_search_entry(void)
{
	return (gtk_search_entry_new());
}

// Function to create a search bar
Tool	*create_search_bar(Tool *entry)
{
	Tool *search_bar = gtk_search_bar_new();
	gtk_search_bar_connect_entry(GTK_SEARCH_BAR(search_bar), GTK_ENTRY(entry));
	return (search_bar);
}

// Function to create a revealer
Tool	*create_revealer(Tool *child, gboolean reveal)
{
	Tool *revealer = gtk_revealer_new();
	gtk_container_add(GTK_CONTAINER(revealer), child);
	gtk_revealer_set_reveal_child(GTK_REVEALER(revealer), reveal);
	return (revealer);
}

// Function to set the revealer's revealed state
void	set_revealer_reveal(Tool *revealer, gboolean reveal)
{
	gtk_revealer_set_reveal_child(GTK_REVEALER(revealer), reveal);
}

// Function to get the revealer's revealed state
gboolean	get_revealer_reveal(Tool *revealer)
{
	return (gtk_revealer_get_reveal_child(GTK_REVEALER(revealer)));
}

// Function to create a stack
Tool	*create_stack(Tool *container)
{
	Tool *stack = gtk_stack_new();
	gtk_container_add(GTK_CONTAINER(container), stack);
	return (stack);
}

// Function to add a widget to a stack
void	add_to_stack(Tool *stack, Tool *widget, const char *name)
{
	gtk_stack_add_named(GTK_STACK(stack), widget, name);
}

// Function to create a stack switcher
Tool	*create_stack_switcher(Tool *stack)
{
	Tool *switcher = gtk_stack_switcher_new();
	gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(switcher), GTK_STACK(stack));
	return (switcher);
}

// Function to create a header bar
Tool	*create_header_bar(const char *title, const char *subtitle)
{
	Tool *header_bar = gtk_header_bar_new();
	gtk_header_bar_set_title(GTK_HEADER_BAR(header_bar), title);
	gtk_header_bar_set_subtitle(GTK_HEADER_BAR(header_bar), subtitle);
	return (header_bar);
}

// Function to add a widget to a header bar
void	add_to_header_bar(Tool *header_bar, Tool *widget)
{
	gtk_header_bar_pack_end(GTK_HEADER_BAR(header_bar), widget);
}

// Function to create a popover
Tool	*create_popover(Tool *relative_to)
{
	return (gtk_popover_new(relative_to));
}

// Function to add a widget to a popover
void	add_to_popover(Tool *popover, Tool *widget)
{
	gtk_container_add(GTK_CONTAINER(popover), widget);
}

// Function to create a progress bar
/*Tool *create_progress_bar(void) {
    return gtk_progress_bar_new();
}*/

// Function to set the progress bar's fraction
void	set_progress_bar_fraction(Tool *progress_bar, double fraction)
{
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), fraction);
}

// Function to create a stack sidebar
Tool	*create_stack_sidebar(Tool *stack)
{
	Tool *sidebar = gtk_stack_sidebar_new();
	gtk_stack_sidebar_set_stack(GTK_STACK_SIDEBAR(sidebar), GTK_STACK(stack));
	return (sidebar);
}

// Function to create a flow box
Tool	*create_flow_box(Tool *container)
{
	Tool *flow_box = gtk_flow_box_new();
	gtk_container_add(GTK_CONTAINER(container), flow_box);
	return (flow_box);
}

// Function to add a widget to a flow box
void	add_to_flow_box(Tool *flow_box, Tool *widget)
{
	gtk_flow_box_insert(GTK_FLOW_BOX(flow_box), widget, -1);
}

// Function to create a level bar
Tool	*create_level_bar(void)
{
	return (gtk_level_bar_new());
}

// Function to set the level bar's value
void	set_level_bar_value(Tool *level_bar, double value)
{
	gtk_level_bar_set_value(GTK_LEVEL_BAR(level_bar), value);
}

// Function to create a short cut button
Tool	*create_shortcut_button(const char *label, GCallback callback, gpointer data)
{
	Tool *shortcut_button = gtk_shortcut_label_new(label);
	g_signal_connect(shortcut_button, "clicked", callback, data);
	return (shortcut_button);
}

// Function to create a status bar
Tool	*create_status_bar(void)
{
	return (gtk_statusbar_new());
}

// Function to create a banner
Tool	*create_banner(const char *text)
{
	Tool *banner = gtk_label_new(text);
	return (banner);
}

// Function to create a header group
Tool	*create_header_group(void)
{
	return (gtk_header_bar_new());
}

// Function to create a suggestion entry
Tool	*create_suggestion_entry(void)
{
	return (gtk_entry_new());
}

// Function to create a feedback bar
Tool	*create_feedback_bar(const char *message)
{
	Tool *feedback_bar = gtk_label_new(message);
	return (feedback_bar);
}

// Function to create a placeholder
Tool	*create_placeholder(const char *text)
{
	Tool *placeholder = gtk_label_new(text);
	return (placeholder);
}

// Function to create a list box
Tool	*create_list_box(Tool *container)
{
	Tool *list_box = gtk_list_box_new();
	gtk_container_add(GTK_CONTAINER(container), list_box);
	return (list_box);
}

// Function to add a widget to a list box
void	add_to_list_box(Tool *list_box, Tool *widget)
{
	gtk_list_box_insert(GTK_LIST_BOX(list_box), widget, -1);
}

// Function to create a sidebar
Tool	*create_sidebar(Tool *container)
{
	Tool *sidebar = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), sidebar);
	return (sidebar);
}

// Function to create a popover menu
Tool	*create_popover_menu(Tool *relative_to, Tool *menu)
{
	Tool *popover = gtk_popover_menu_new();
	gtk_popover_set_relative_to(GTK_POPOVER(popover), relative_to);
	gtk_popover_set_modal(GTK_POPOVER(popover), G_MENU_MODEL(menu));
	return (popover);
}

// Function to create a modal dialog
Tool	*create_modal_dialog(GtkWindow *parent, const char *title, const char *message)
{
	Tool *dialog = gtk_dialog_new_with_buttons(title, parent, GTK_DIALOG_MODAL,
	"_OK", GTK_RESPONSE_OK, NULL);
	Tool *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
	Tool *label = gtk_label_new(message);
	gtk_container_add(GTK_CONTAINER(content_area), label);
	return (dialog);
}

// Function to create a preferences dialog
Tool	*create_preferences_dialog(GtkWindow *parent)
{
	Tool *dialog = gtk_dialog_new_with_buttons("Preferences", parent,
	GTK_DIALOG_MODAL, "_OK", GTK_RESPONSE_OK, "_Cancel", GTK_RESPONSE_CANCEL, NULL);
	return (dialog);
}

// Function to create a context menu
Tool	*create_context_menu(Tool *widget, GCallback callback, gpointer data)
{
	Tool *menu = gtk_menu_new();
	g_signal_connect(menu, "button-press-event", callback, data);
	return (menu);
}

// Function to add a menu item to a context menu
void	add_menu_item_to_context_menu(Tool *menu,
			const char *label, GCallback callback, gpointer data)
{
	Tool *menu_item = gtk_menu_item_new_with_label(label);
	g_signal_connect(menu_item, "activate", callback, data);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
}

// Function to create a grid
/*Tool *create_grid(Tool *container) {
    Tool *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(container), grid);
    return grid;
}
*/
// Function to attach a widget to a grid
void	attach_to_grid(Tool *grid,
			Tool *widget, int left, int top, int width, int height) 
{
	gtk_grid_attach(GTK_GRID(grid), widget, left, top, width, height);
}

// Function to create a scale button
Tool	*create_scale_button(GtkIconSize size, double min, double max, double step)
{
	return (gtk_scale_button_new(size, min, max, step, NULL));
}

/*void set_label_color(Tool *label, const char *css_color) {
    GtkCssProvider *provider = gtk_css_provider_new();
    char *css = g_strdup_printf("label { color: %s; }", css_color);
    gtk_css_provider_load_from_data(provider, css, -1, NULL);
    gtk_style_context_add_provider(gtk_widget_get_style_context(label), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_free(css);
    g_object_unref(provider);
}
*/

// Function to create a drop down menu
/*Tool *create_dropdown_menu(Tool *button, Tool *menu) {
    Tool *dropdown = gtk_menu_new();
    gtk_menu_attach_to_widget(GTK_MENU(dropdown), button, NULL);
    gtk_menu_get_attach_widget(GTK_MENU(dropdown), menu);
    return dropdown;
}
*/

// Function to create a collapsible list
Tool	*create_collapsible_list(Tool *container)
{
	Tool *collapsible_list = gtk_list_box_new();
	gtk_container_add(GTK_CONTAINER(container), collapsible_list);
	return (collapsible_list);
}

// Function to add a widget to a collapsible list
void	add_to_collapsible_list(Tool *collapsible_list, Tool *widget)
{
	gtk_list_box_insert(GTK_LIST_BOX(collapsible_list), widget, -1);
}

// Function to create a panel
Tool	*create_panel(Tool *container)
{
	Tool *panel = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), panel);
	return (panel);
}

// Function to create a breadcrumb
Tool	*create_breadcrumb(Tool *container)
{
	Tool *breadcrumb = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_container_add(GTK_CONTAINER(container), breadcrumb);
	return (breadcrumb);
}

// Function to add a widget to a breadcrumb
void	add_to_breadcrumb(Tool *breadcrumb, Tool *widget)
{
	gtk_box_pack_start(GTK_BOX(breadcrumb), widget, FALSE, FALSE, 0);
}

// Function to create a header
Tool	*create_header(Tool *container)
{
	Tool *header = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_container_add(GTK_CONTAINER(container), header);
	return (header);
}

// Function to add a widget to a header
void	add_to_header(Tool *header, Tool *widget)
{
	gtk_box_pack_start(GTK_BOX(header), widget, FALSE, FALSE, 0);
}

// Function to create a toolbar
/*Tool *create_toolbar(Tool *container) {
    Tool *toolbar = gtk_toolbar_new();
    gtk_container_add(GTK_CONTAINER(container), toolbar);
    return toolbar;
}
*/
// Function to add a widget to a toolbar
void	add_to_toolbar(Tool *toolbar, Tool *widget)
{
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), GTK_TOOL_ITEM(widget), -1);
}

// Function to create a navigation bar
Tool	*create_navigation_bar(Tool *container)
{
	Tool *navigation_bar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_container_add(GTK_CONTAINER(container), navigation_bar);
	return (navigation_bar);
}

// Function to add a widget to a navigation bar
void	add_to_navigation_bar(Tool *navigation_bar, Tool *widget)
{
	gtk_box_pack_start(GTK_BOX(navigation_bar), widget, FALSE, FALSE, 0);
}

// Function to create a sidebar menu
Tool	*create_sidebar_menu(Tool *container)
{
	Tool *sidebar_menu = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), sidebar_menu);
	return (sidebar_menu);
}

// Function to create a navigation drawer
Tool	*create_navigation_drawer(Tool *container)
{
	Tool *navigation_drawer = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), navigation_drawer);
	return (navigation_drawer);
}

// Function to add a widget to a navigation drawer
void	add_to_navigation_drawer(Tool *navigation_drawer, Tool *widget)
{
	gtk_box_pack_start(GTK_BOX(navigation_drawer), widget, FALSE, FALSE, 0);
}

// Function to create a tile
Tool	*create_tile(Tool *container)
{
	Tool *tile = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_container_add(GTK_CONTAINER(container), tile);
	return (tile);
}

// Function to create a tab bar
Tool	*create_tab_bar(Tool *container)
{
	Tool *tab_bar = gtk_notebook_new();
	gtk_container_add(GTK_CONTAINER(container), tab_bar);
	return (tab_bar);
}

// Function to add a widget to a tab bar
void	add_to_tab_bar(Tool *tab_bar, Tool *widget, const char *label)
{
	gtk_notebook_append_page(GTK_NOTEBOOK(tab_bar), widget, gtk_label_new(label));
}

// Function to create a sidebar panel
Tool	*create_sidebar_panel(Tool *container) {
	Tool *sidebar_panel = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), sidebar_panel);
	return (sidebar_panel);
}

// Function to add a widget to a sidebar panel
void	add_to_sidebar_panel(Tool *sidebar_panel, Tool *widget)
{
	gtk_box_pack_start(GTK_BOX(sidebar_panel), widget, FALSE, FALSE, 0);
}

// Function to create a floating button
Tool	*create_floating_button(const char *label, GCallback callback, gpointer data)
{
	Tool *button = gtk_button_new_with_label(label);
	g_signal_connect(button, "clicked", callback, data);
	return (button);
}

// Function to create a notification banner
Tool	*create_notification_banner(const char *message)
{
	Tool *notification_banner = gtk_label_new(message);
	return (notification_banner);
}

// Function to create a dropdown list
Tool	*create_dropdown_list(Tool *container)
{
	Tool *dropdown_list = gtk_combo_box_text_new();
	gtk_container_add(GTK_CONTAINER(container), dropdown_list);
	return (dropdown_list);
}

// Function to add an item to a dropdown list
void	add_to_dropdown_list(Tool *dropdown_list, const char *item)
{
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dropdown_list), item);
}

// Function to create a collapsible sidebar
Tool	*create_collapsible_sidebar(Tool *container)
{
	Tool *collapsible_sidebar = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), collapsible_sidebar);
	return (collapsible_sidebar);
}

// Function to create a notification center
Tool	*create_notification_center(Tool *container)
{
	Tool *notification_center = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), notification_center);
	return (notification_center);
}

// Function to create a status widget
Tool	*create_status_widget(const char *status)
{
	Tool *status_widget = gtk_label_new(status);
	return (status_widget);
}

// Function to create a tooltip
Tool	*create_tooltip(const char *text)
{
	Tool *tooltip = gtk_label_new(text);
	return (tooltip);
}

// Function to create a collapsible header
Tool	*create_collapsible_header(const char *label)
{
	Tool *collapsible_header = gtk_expander_new(label);
	return (collapsible_header);
}

// Function to set the collapsible header's expanded state
void	set_collapsible_header_expanded(Tool *collapsible_header, gboolean expanded)
{
	gtk_expander_set_expanded(GTK_EXPANDER(collapsible_header), expanded);
}

// Function to get the collapsible header's expanded state
gboolean	get_collapsible_header_expanded(Tool *collapsible_header)
{
	return (gtk_expander_get_expanded(GTK_EXPANDER(collapsible_header)));
}

// Function to create a section header
Tool	*create_section_header(const char *label)
{
	Tool *section_header = gtk_label_new(label);
	return (section_header);
}

// Function to create a sidebar header
Tool	*create_sidebar_header(const char *label)
{
	Tool *sidebar_header = gtk_label_new(label);
	return (sidebar_header);
}

// Function to create a breadcrumb header
Tool	*create_breadcrumb_header(const char *label)
{
	Tool *breadcrumb_header = gtk_label_new(label);
	return (breadcrumb_header);
}
// Function to create a toggle switch
Tool	*create_toggle_switch(gboolean state)
{
	Tool *toggle_switch = gtk_switch_new();
	gtk_switch_set_active(GTK_SWITCH(toggle_switch), state);
	return (toggle_switch);
}

// Function to create a dropdown button
Tool	*create_dropdown_button(const char *label, GCallback callback, gpointer data)
{
	Tool *button = gtk_button_new_with_label(label);
	g_signal_connect(button, "clicked", callback, data);
	return (button);
}

// Function to create a quick access panel
Tool	*create_quick_access_panel(Tool *container)
{
	Tool *quick_access_panel = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), quick_access_panel);
	return (quick_access_panel);
}

// Function to add a widget to a quick access panel
void	add_to_quick_access_panel(Tool *quick_access_panel, Tool *widget)
{
	gtk_box_pack_start(GTK_BOX(quick_access_panel), widget, FALSE, FALSE, 0);
}

// Function to create a progress tracker
Tool	*create_progress_tracker(void)
{
	return (gtk_progress_bar_new());
}

// Function to set the progress tracker's value
void	set_progress_tracker_value(Tool *progress_tracker, double value)
{
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_tracker), value);
}

// Function to create a floating action button
Tool	*create_floating_action_button(const char *label,
				GCallback callback, gpointer data)
{
	Tool *button = gtk_button_new_with_label(label);
	g_signal_connect(button, "clicked", callback, data);
	return (button);
}

// Function to create a collapsible panel
Tool	*create_collapsible_panel(Tool *container)
{
	Tool *collapsible_panel = gtk_expander_new("");
	gtk_container_add(GTK_CONTAINER(container), collapsible_panel);
	return (collapsible_panel);
}

// Function to add a widget to a collapsible panel
void	add_to_collapsible_panel(Tool *collapsible_panel, Tool *widget)
{
	gtk_container_add(GTK_CONTAINER(collapsible_panel), widget);
}

// Function to create a navigation rail
Tool	*create_navigation_rail(Tool *container)
{
	Tool *navigation_rail = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), navigation_rail);
	return (navigation_rail);
}

// Function to create a quick settings panel
Tool	*create_quick_settings_panel(Tool *container)
{
	Tool *quick_settings_panel = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), quick_settings_panel);
	return (quick_settings_panel);
}

// Function to add a widget to a quick settings panel
void add_to_quick_settings_panel(Tool *quick_settings_panel, Tool *widget)
{
	gtk_box_pack_start(GTK_BOX(quick_settings_panel), widget, FALSE, FALSE, 0);
}

// Function to create a navigation menu
Tool	*create_navigation_menu(Tool *container)
{
	Tool *navigation_menu = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), navigation_menu);
	return (navigation_menu);
}

// Function to create a sidebar list
Tool	*create_sidebar_list(Tool *container)
{
	Tool *sidebar_list = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), sidebar_list);
	return (sidebar_list);
}

// Function to create a navigation list
Tool	*create_navigation_list(Tool *container)
{
	Tool *navigation_list = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), navigation_list);
	return (navigation_list);
}

// Function to create a navigation panel
Tool	*create_navigation_panel(Tool *container)
{
	Tool *navigation_panel = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), navigation_panel);
	return (navigation_panel);
}

// Function to create a quick panel
Tool	*create_quick_panel(Tool *container)
{
	Tool *quick_panel = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), quick_panel);
	return (quick_panel);
}

// Function to create a navigation header
Tool	*create_navigation_header(const char *label)
{
	Tool *navigation_header = gtk_label_new(label);
	return (navigation_header);
}

// Function to create a navigation footer
Tool	*create_navigation_footer(const char *label)
{
	Tool *navigation_footer = gtk_label_new(label);
	return (navigation_footer);
}

// Function to create a floating toolbar
Tool	*create_floating_toolbar(Tool *container)
{
	Tool *floating_toolbar = gtk_toolbar_new();
	gtk_container_add(GTK_CONTAINER(container), floating_toolbar);
	return (floating_toolbar);
}

// Function to add a widget to a floating toolbar
void	add_to_floating_toolbar(Tool *floating_toolbar, Tool *widget) {
    gtk_toolbar_insert(GTK_TOOLBAR(floating_toolbar), GTK_TOOL_ITEM(widget), -1);
}

// Function to create a navigation indicator
Tool	*create_navigation_indicator(const char *label)
{
	Tool *navigation_indicator = gtk_label_new(label);
	return (navigation_indicator);
}

// Function to create a navigation view
Tool	*create_navigation_view(Tool *container)
{
	Tool *navigation_view = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(container), navigation_view);
	return (navigation_view);
}

// Function to create a navigation control
Tool	*create_navigation_control(Tool *container)
{
	Tool *navigation_control = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_container_add(GTK_CONTAINER(container), navigation_control);
	return (navigation_control);
}

// Function to add a widget to a navigation control
void	add_to_navigation_control(Tool *navigation_control, Tool *widget)
{
	gtk_box_pack_start(GTK_BOX(navigation_control), widget, FALSE, FALSE, 0);
}

// Function to create a navigation separator
Tool	*create_navigation_separator(void)
{
	return (gtk_separator_new(GTK_ORIENTATION_HORIZONTAL));
}

// Function to create a quick action
Tool	*create_quick_action(const char *label, GCallback callback, gpointer data)
{
	Tool *quick_action = gtk_button_new_with_label(label);
	g_signal_connect(quick_action, "clicked", callback, data);
	return (quick_action);
}

// Function to create a quick shortcut
Tool	*create_quick_shortcut(const char *label, GCallback callback, gpointer data)
{
	Tool *quick_shortcut = gtk_button_new_with_label(label);
	g_signal_connect(quick_shortcut, "clicked", callback, data);
	return (quick_shortcut);
}

// Function to create a quick link
Tool *create_quick_link(const char *label, GCallback callback, gpointer data)
{
	Tool *quick_link = gtk_button_new_with_label(label);
	g_signal_connect(quick_link, "clicked", callback, data);
	return (quick_link);
}

// Função para iniciar o loop principal do GTK
/*void loop(gpointer user_data)
{
    if (init_callback != NULL)
    {
        initialize_app(user_data);
    }
    gtk_main();
}*/
