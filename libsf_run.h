#ifndef LIBSF_RUN_H
# define LIBSF_RUN_H

# include "libsf.h"

// GtkFileChooserButton macros
// Macro para criar um botão de escolha de arquivo com a ação de abrir
#define create_file_chooser_button(opene) \
    gtk_file_chooser_button_new(opene, GTK_FILE_CHOOSER_ACTION_OPEN)

// Macro para obter o nome do arquivo selecionado no botão de escolha de arquivo
#define get_file_chooser_file(button) \
    gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(button))

// GtkToggleButton macros
// Macro para criar um botão de alternância (toggle button) com um rótulo
#define new_toggle(label) \
    gtk_toggle_button_new_with_label(label)

// Macro para verificar se um botão de alternância está ativo
#define is_toggl_active(toggle) \
    gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(toggle))

// GtkCheckButton macros
// Macro para criar um botão de seleção (check button) com um rótulo
#define new_check_button(label) \
    ({ \
        GtkWidget *check_button = gtk_check_button_new_with_label(label); \
        check_button; \
    })

// Macro para definir o estado ativo de um botão de seleção
#define set_check_button_active(button, active) \
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button), active)

// Macro para verificar se um botão de seleção está ativo
#define is_check_button_active(button) \
    gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button))

// GtkRadioButton macros
// Macro para criar um botão de rádio com um rótulo, pertencente a um grupo
#define new_radio_button(group, label) \
    ({ \
        GtkWidget *radio_button = gtk_radio_button_new_with_label(group, label); \
        radio_button; \
    })

// Macro para verificar se um botão de rádio está ativo
#define is_radio_button_active(button) \
    gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button))

// Macro para definir o estado ativo de um botão de rádio
#define set_radio_button_active(button, active) \
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button), active)

// GtkScale macros
// Macro para criar um controle deslizante (scale) com intervalo e passo definidos
#define new_scale(orientation, min, max, step) \
    ({ \
        GtkWidget *scale = gtk_scale_new_with_range(orientation, min, max, step); \
        scale; \
    })

// Macro para definir o valor de um controle deslizante
#define set_scale_value(scale, value) \
    gtk_range_set_value(GTK_RANGE(scale), value)

// Macro para obter o valor de um controle deslizante
#define get_scale_value(scale) \
    gtk_range_get_value(GTK_RANGE(scale))

// GtkSwitch macros
// Macro para criar um interruptor (switch)
#define new_switch() \
    gtk_switch_new()

// Macro para definir o estado ativo de um interruptor
#define set_switch_active(switch, active) \
    gtk_switch_set_active(GTK_SWITCH(switch), active)

// Macro para verificar se um interruptor está ativo
#define is_switch_active(switch) \
    gtk_switch_get_active(GTK_SWITCH(switch))

//typedef GtkWidget CheckButton;
//typedef GtkWidget ToggleButton;
//typedef GtkWidget RadioButton;

// Imagens
//typedef GtkWidget Image;
//typedef GtkWidget ImageFromPixbuf;

// Labels e textos
//typedef GtkWidget Label;
//typedef GtkWidget Entry;
//typedef GtkWidget Text;

// Contêineres e layout
//typedef GtkWidget Box;
//typedef GtkWidget Fixed;
//typedef GtkWidget Paned;
//typedef GtkWidget ScrolledWindow;
//typedef GtkWidget Notebook;

// Controles de visualização
//typedef GtkWidget TreeView;
//typedef GtkWidget TreeViewColumn;
//typedef GtkWidget ProgressBar;
//typedef GtkWidget Scale;
//typedef GtkWidget SpinButton;
//typedef GtkWidget Adjustment;

// Diálogos e janelas
//typedef GtkWidget Window;
//typedef GtkWidget FileDialog;
//typedef GtkWidget ColorDialog;
//typedef GtkWidget FontDialog;

// Outros
//typedef GtkWidget DrawingArea;
//typedef GtkWidget Separator;
//typedef GtkWidget Spinner;
//typedef GtkWidget MenuItem;
//typedef GtkWidget IconButton;
//typedef GtkWidget CheckButton;
//typedef GtkWidget ComboBox;
//typedef GtkWidget Box;
//typedef GtkWidget EntryWithPlaceholder;

// Tipos adicionais
//typedef GtkWidget ButtonWithIcon;
//typedef GtkWidget ImageFromPixbuf;
//typedef GtkWidget EntryWithPlaceholder;




void mause_click(GtkWidget *widget, int button, void (*func)(GtkWidget*, void*), void *pointer);




const char*	get_text_button(GtkWidget *button);
const char*	get_name(GtkWidget *widget);
GtkStyleProvider*	get_style(GtkStyleContext *context);
GdkPixbuf*	get_image_pixbuf(GtkImage *image);
gdouble	get_progress_value(GtkProgressBar *progress_bar);
GSList*	get_radio_group(GtkRadioButton *radio_button);
//void	get_fixed_position(GtkWidget *fixed,	GtkWidget *widget, int *x, int *y);
const char*	get_label(GtkWidget *label);
//GType	get_window_type(GtkWidget *window);
const char*	get_entry_text(GtkEntry *entry);
gboolean	get_toggle_state(GtkToggleButton *toggle);
GtkWidget*	get_combo_active(GtkComboBoxText *combo);
GtkWidget*	get_tree_view_column(int c,	GtkTreeView *tree_view);
GtkWidget*	get_file_dialog(GtkFileChooserDialog *dialog);
//GdkColor	get_color(GtkColorButton *color_button);
PangoFontDescription*	get_font_description(GtkFontButton *font_button);
gdouble	get_spin_value(GtkSpinButton *spin);
void	get_scrolled_window(GtkScrolledWindow *scrolled_window,	GtkAdjustment **hadjustment,	GtkAdjustment **vadjustment);
GtkWidget*	get_paned(GtkWidget *paned);
GtkWidget*	get_dialog(GtkDialog *dialog);
GtkWidget*	get_container(GtkContainer *container);

GtkWidget*	sf_new_button(const char *label);
void	sf_set_button_label(GtkWidget *button, const char *label);
void	sf_set_name(GtkWidget *widget, const char *name);
void	sf_add_style(GtkStyleContext *context,	GtkStyleProvider *provider,	GtkStyleProvider_autoptr priority);
GtkWidget*	sf_new_image(const char *filename);
GtkWidget*	sf_new_progress(void);
void	sf_set_radio_group(GtkRadioButton *radio_button,	GSList *group);
void	print_fixed(GtkWidget *fixed, GtkWidget *widget, int x, int y);
GtkWidget*	sf_new_label(const char *label);
GtkWidget*	sf_new_window(GtkWindowType type);
GtkWidget*	sf_new_entry(void);
GtkWidget*	sf_new_toggle(void);
GtkWidget*	sf_new_combo(void);


void	sf_pack_start(GtkBox *box,	GtkWidget *widget,	gboolean expand,	gboolean fill,	guint padding);
void	sf_show_all(GtkWidget *widget);
void	sf_add_to_container(GtkContainer *container,	GtkWidget *widget);
GtkWidget*	sf_new_tree_view(void);
void	sf_append_column(GtkTreeView *tree_view,	GtkTreeViewColumn *column);
GtkWidget*	sf_new_file_dialog(GtkWindow *parent, const char *title,	GtkFileChooserAction action);
int	sf_run_dialog(GtkDialog *dialog);
void	sf_destroy_widget(GtkWidget *widget);
void	sf_main_loop(void);
void	sf_quit(void);
//void	get_scrolled_window(GtkScrolledWindow *scrolled_window, GtkAdjustment **hadjustment, GtkAdjustment **vadjustment);
GtkWidget*	sf_new_menu_item(const char *label);
GtkWidget*	sf_new_scrolled_window(void);
GtkWidget*	sf_new_paned(void);
GtkWidget*	sf_new_scale(GtkOrientation orientation);
GtkWidget*	sf_new_spin(double min, double max, double step);
GtkWidget*	sf_color_dialog(const char *title,	GtkWindow *parent);
GtkWidget*	sf_font_dialog(const char *title,	GtkWindow *parent);
GtkWidget*	sf_new_box(GtkOrientation orientation);
GtkWidget*	sf_new_button_with_icon(const char *icon_name);
GtkWidget*	sf_new_image_from_pixbuf(GdkPixbuf *pixbuf);
void	sf_set_widget_size(GtkWidget *widget, int width, int height);
void	sf_set_widget_visibility(GtkWidget *widget,	gboolean visible);
void	sf_set_widget_sensitive(GtkWidget *widget,	gboolean sensitive);
void	sf_set_widget_margin(GtkWidget *widget, int margin);
GtkWidget*	sf_new_check_button(const char *label);
GtkWidget*	sf_new_separator(GtkOrientation orientation);
void	sf_set_text(GtkLabel *label, const char *text);
GtkWidget*	sf_new_spinner(void);
void	sf_start_spinner(GtkSpinner *spinner);
void	sf_stop_spinner(GtkSpinner *spinner);
GtkWidget*	sf_new_adjustment(double value, double lower, double upper, double step_increment, double page_increment, double page_size);
void	sf_set_adjustment(GtkAdjustment *adjustment, double value, double lower, double upper, double step_increment, double page_increment, double page_size);
GtkWidget*	sf_new_scrolled_window_with_adjustments(GtkAdjustment *hadjustment,	GtkAdjustment *vadjustment);
GtkWidget*	sf_new_drawing_area(void);
void	sf_set_drawing_area_size(GtkDrawingArea *drawing_area, int width, int height);
GtkWidget*	sf_new_entry_with_placeholder(const char *placeholder);
GtkWidget*	sf_new_scale_with_range(GtkOrientation orientation, double min, double max, double step);
void	sf_set_scale_value(GtkScale *scale, double value);
GtkWidget*	sf_new_notebook(void);
void	sf_add_notebook_page(GtkNotebook *notebook,	GtkWidget *child, const char *tab_label);


#endif
