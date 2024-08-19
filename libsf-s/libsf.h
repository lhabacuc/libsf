#ifndef LIBSF_H
# define LIBSF_H

# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <math.h>
# include <cairo.h>
# include <gtk/gtk.h>
# include <errno.h>
# include "libsff.h"
# include "libsf_run.h"
//gcc -o app t.c -I./libsf-s -L./libsf-s -lsf `pkg-config --cflags --libs gtk+-3.0`

// Estrutura para gerenciar diferentes janelas no aplicativo
typedef struct s_window_manager
{
	Tool	*main_window;
	Tool	*settings_window;
	Tool	*content_window;
	Tool	*dialog_window;	
	Tool	*tools_window;	
	Tool	*help_window;	
	Tool	*temp_window;	
	Tool	*fixed_layout_window;	
	Tool	*grid_layout_window;
	Tool	*data_window;
	Tool	*preview_window;
	Tool	*widget; 
	Tool	*area_desenho;	
	Tool	*barra_status;
	Tool	*menu_principal;
	Tool	*painel_ferrament;
	gint		x;
	gint		y;
	gint		largura;
	gint		altura; 
}			t_window_manager;

typedef enum
{
	GONE,       // estado 0: 
	VISIVEL,    // estado 1:
	INVISIVEL   // estado 2: 
}	Status;

typedef struct s_imagem
{
	Tool    *Ob;         
	Tool     *fixed;     
	int          x;           
	int          y;           
	int          largura;     
	int          altura;      
	gchar        *file_path;  
	guint32		bcor;
	guint32      cor;         
	int          trans;       
	int bord; 
	Status       visivel;     
} Imagem;

typedef struct s_entry
{
	Tool *Ob;            
	Tool *fixed;         
	int x;                    
	int y;                    
	int largura;              
	int altura;               
	char *texto;              
	guint32 cor;              
	guint32 textcor;          
	guint32 bcor;
	gboolean (*func)(Tool *, gpointer);
	int bord;
	int	event;
	Status visivel;
	int trans;
	gpointer dados_adicionais;
} Edtext;

typedef	gboolean (*ButtonCallbackFunc)(Tool *widget, cairo_t *cr, gpointer data);

typedef struct s_butoon
{
	Tool    *Ob;
	Tool     *fixed;
	int          x;
	int          y;
	int          largura;
	int          altura;
	char         *texto;
	guint32      cor;
	guint32      textcor;
	guint32      bcor;
	ButtonCallbackFunc     func;
	int          bord;
	int		event;
	Status       visivel;
	int          trans;
	gpointer     dados_adicionais;
} Butoon;

typedef struct s_drawing_area
{
	Tool    *Ob;
	Tool     *fixed;
	int          x;
	int          y;
	int          largura;  
	int          altura; 
	int          bord; 
	guint32      cor; 
	guint32 bcor; 
	Status       visivel;
	gboolean     (*draw_callback)(Tool *, cairo_t *, gpointer); 
	gpointer     data;  
} DrawingArea;

typedef struct s_label
{
	Tool    *Ob;  
	Tool     *fixed;            
	int          x;   
	int          y;       
	int          largura;  
	int          altura; 
	gchar        *texto; 
	guint32      cor;
	guint32      textcor;
	int          trans; 
	Status       visivel; 
	int          bord;   
	guint32      bcor;
} Label;

typedef struct s_separator
{
	Tool *Ob;
	Tool *fixed;
	int x;
	int y;
	int largura;
	int altura;
	guint32 cor;
	Status visivel;
} Separator;


typedef struct s_slider
{
	Tool *Ob;
	Tool *fixed;
	int x;
	int y;
	int largura;
	int altura;
	double value;
	double min_value;
	double max_value;
	Status visivel;
	guint32 cor;
	void (*value_changed_callback)(Tool *, gpointer);
	gpointer data;
} Slider;

typedef struct s_status_bar
{
	Tool *Ob;
	Tool *fixed;
	int x;
	int y;
	int          bord;
	guint32      bcor;
	guint32      cor;
	guint32      textcor;
	int largura;
	int altura;
	Status visivel;
	char *message;
} StatusBar;

typedef struct s_file_chooser
{
	Tool				*Ob;
	Tool				*fixed;
	int						x;
	int						y;
	int						largura;
	int						altura;
	GtkFileChooserAction	action;
	char					*title;      
	unsigned int			cor;                 
	int						bord;
	unsigned int			bcor;              
	Status					visivel;
	void					(*file_activated_callback)(Tool *, gpointer);
	gpointer				data;
} FileChooser;

typedef struct	s_context_menu
{
	Tool		*fixed;
	Tool		*Ob;  
	GtkCssProvider	*css_provider;
	char			**items;
	void			(**item_callbacks)(Tool *, gpointer);
	gpointer		*item_data; 
	int				item_count;  
	int				x, y;        
	int				largura;     
	int				altura;   
	unsigned int	cor;             
	unsigned int	textcor;          
	int				bord;          
	unsigned int	bcor;             
	int				visivel;          
}				ContextMenu;


typedef struct s_progress_bar {
	Tool *Ob;       
	Tool *fixed;     
	int x;                
	int y;            
	int largura;      
	int altura;            
	double valor;    
	guint32 cor;    
	guint32 bcor;      
	gboolean (*update_callback)(Tool *, gpointer);
	gpointer update_callback_data;  
	int bord;                   
	Status visivel;             
	int trans;                
} ProgressBar;

typedef struct s_radio_button
{
	Tool *Ob;
	Tool *fixed;
	int x;
	int y;
	int largura;
	int altura;
	char *label;
	int          bord;
	guint32      bcor;
	guint32      cor;
	guint32      textcor;
	gboolean active;
	Status visivel;
	void (*toggled_callback)(Tool *, gpointer);
	gpointer data;
} RadioButton;

typedef struct
{
	Tool	*widget;
	int		x;	
	int		y;	
	int		largura;
	int		altura;	
	gboolean	visivel;
	GdkRGBA	cor_fundo;		
	GdkRGBA	cor_borda;		
	int		espessura_borda;
	gchar		*texto;		
	PangoFontDescription	*fonte;
	gboolean	visivel_borda;
	gdouble	transparencia;	
	gboolean	animado;
	gpointer	animacao_dados;
	guint		tipo_widget;	
	Tool	*anexos;
	void		(*desenho_callback)(Tool *, cairo_t *, gpointer);
	gpointer	dados;
}	Objeto;


typedef struct
{
	void	(*key_handler)(GdkEventKey *event, gpointer user_data);
	gpointer	user_data;
}			t_key_event_data;

typedef struct
{
	void	(*mouse_handler)(GdkEventButton *event, gpointer user_data);
	gpointer	user_data;
}			t_mouse_event_data;

typedef struct
{
	void	(*loop_handler)(gpointer user_data);
	gpointer	user_data;
}			t_loop_event_data;

typedef void (*ItemClickedCallback)(GtkListBox *, GtkListBoxRow *, gpointer);

typedef struct {
    GtkWidget *listbox;
    GtkWidget *fixed;
    int largura;
    int altura;
    int x;
    int y;
    int item_height;
    int item_width;
    int item_count;
    gchar **items;
    void (*item_clicked_callback)(GtkListBox *, GtkListBoxRow *, gpointer);
    gpointer callback_data;
    gboolean vertical;
    gboolean visivel;
    gchar *background_color;
    gchar *item_color;
    gchar *border_color;
    int border_width;
} LinearView;



typedef struct {
	Tool *Ob;
	Tool *fixed;
	char *texto;
	int largura;
	int altura;
	int x;
	int y;
	int cor;
	int textcor;
	int bord;
	int bcor;
	int visivel;
	gboolean resizable;
	void (*func)(GtkTextBuffer *, gpointer);
	gpointer dados_adicionais;
} TextView;

void		window_center(Tool *window, int window_width, int window_height);
void		init_win_position(Tool *window, int x, int y);
void		event_hook(GtkWidget *widget, int event, SignalCallback callback, Pont data);

String		get_EText(GtkWidget *entry);
void		set_EText(GtkWidget *entry, char *str);

char		*get_uni_name(char *nome);
void		init_butoon(Butoon *btl);
void		init_label(Label *lbl);
void		init_EText(Edtext *ent);
void		init_imagem(Imagem *img);
void		init_drawing_area(DrawingArea *da);
void		init_separator(Separator *sep);
void		init_slider(Slider *sl);
void		init_status_bar(StatusBar *sb);
void		init_file_chooser(FileChooser *fc);
void		init_radio_button(RadioButton *rb);
void		init_text_view(TextView *tv);
void		criar_grade_locali(GtkFixed *fixed, int larg, int altur);

/*	database sharepreferense	*/
void		create_directory(const char *path);
void		create_new_database(const char *db_name, const char *arquivo);
char		*get_value(const char *db_name, const char *key, const char *arquivo);
void		delete_record(const char *db_name, const char *key, const char *arquivo);
void		add_or_update_record(const char *db_name, const char *key,const char *value,
				const char *arquivo);
				
unsigned int			hash(const char *key);
void		map_init(t_map *map);
void		map_put(t_map *map, const char *key, const char *value);
int		map_get(t_map *map, const char *key, char **value);
void		map_remove(t_map *map, const char *key);
void		map_free(t_map *map);
void		map_save_to_file(t_map *map, const char *filename);
void		map_load_from_file(t_map *map, const char *filename);
/*		test database		*/
void		listar_registros(const char *db_name, const char *arquivo);
void		set_size(Tool *widget, int width, int height);
void		on_item(GtkListBox *listbox, GtkListBoxRow *row, gpointer user_data);

void	init_linear_view(LinearView *lv);
Tool	*create_window_p(const char *title, int width, int height, gboolean resizable);
Tool	*fixed_layout_window(Tool *window);
Tool	*create_context_menu(Tool *widget, GCallback callback, gpointer data);
Tool	*create_window_s(const char *title, int width, int height);
Tool	*add_button(Tool *fixed, const char *button_text, int x, int y, BCall callback, Pont data);
Tool	*add_label(Tool *container, const char *text, int x, int y);
Tool	*add_EText(Tool *container, int x, int y, int event, ECall callback, Pont data);
Tool	*add_color_chooser(Tool *container, int x, int y, GCallback callback);
Tool	*add_drawing_area(Tool *container, int x, int y,
				int width, int height, GCallback draw_callback);
Tool	*add_file_chooser(Tool *container, int x, int y, GCallback callback);
Tool	*add_image(Tool *container, const char *file_path, int x, int y);
Tool	*add_separator(Tool *container, int x, int y, gboolean horizontal);
Tool	*add_volume_slider(Tool *container, int x, int y, GCallback callback);
Tool	*add_checkbox(Tool *container, const char *label, int x, int y, GCallback callback);
Tool	*add_radio_button(Tool *container,
				Tool *group, const char *label, int x, int y);
Tool	*add_combo_box(Tool *container, int x, int y,
				gchar **items, int item_count, GCallback callback);
Tool	*add_calendar(Tool *container, int x, int y, GCallback callback);
Tool	*add_status_bar(Tool *container, int x, int y);
Tool	*add_context_menu(Tool *widget, Tool *menu);
Tool	*add_toolbar_with_buttons(Tool *container, const char **button_labels, int count);
Tool	*add_spinner(Tool *container, int x, int y);
Tool	*add_text_view(Tool *container, int x, int y, int width, int height);

Tool	*create_image_with_position(Tool *container, const char *file_path,
					int x, int y, int width, int height);
Tool	*create_scale_with_position(Tool *container,
					int x, int y, int min, int max, int step);
Tool	*create_checkbox_with_position(Tool *container,
				const char *label, int x, int y, gboolean active);
Tool	*create_drawing_area_with_position(Tool *container,
			int x, int y, int width,int height,
			gboolean (*draw_callback)(Tool *, cairo_t *, gpointer), gpointer data);
Tool	*create_label_with_position(Tool *container, const char *text,
				int x, int y, const GdkRGBA *color);
Tool	*create_button_with_position(Tool *container, const char *label,
				int x, int y, void (*callback)(Tool *, gpointer), gpointer data);

Tool	*create_check_button(const char *label, gboolean initial_state);
Tool	*create_progress_bar(double initial_fraction);
Tool	*create_spin_button(double min, double max, double step, double initial_value);
Tool	*create_combo_box(const char **items, int num_items, int default_index);
Tool	*create_image_ph(Tool *container, const char
					*file_path, gint x, gint y, gint width, gint height);
Tool	*create_vbox(gboolean homogeneous, gint spacing);
Tool	*create_hbox(gboolean homogeneous, gint spacing);
Tool	*create_grid(gint row_spacing, gint column_spacing);
Tool	*create_fixed_layout(void);
Tool	*create_entry1(GtkFixed *fixed, gint x, gint y, const char *border_color,
					void (*callback)(GtkEntry *, gpointer));
Tool	*create_label(Tool *container, const char *text);
Tool	*create_text_view(Tool *container);
Tool	*new_window(const char *title, int width, int height);
GtkFixed	*initialize_layout(Tool *window);
Tool* create_window(const char *title, int width, int height, gboolean resizable);

char	*if_event(int event);
int	appl_run(Appl *app, int argc, char **argv);
void	appl_activate(Appl *app, GCallback activate_callback, Pont user_data);
Appl	*appl_new(const char *app_id);

void		center_img(GtkFixed *fixed, const char *image, int window_w, int window_h, int r);
void		set_window_background(Tool *window, guint color_hex);
void		init_butoon(Butoon *btl);
void		loop(gpointer user_data);
void		hook(Tool *widget, int event, GCallback callback, gpointer user_data);
void		set_background_color(Tool *widget, const gchar *color);
void		hide_widget(Tool *widget);
void		show_widget(Tool *widget);
void		pixel_put(Tool *drawing_area, int x, int y, double red, double green, double blue);
void		hook_key(Tool *widget, void (*key_handler)(GdkEventKey *event, gpointer user_data), gpointer user_data);
void		set_size(Tool *widget, int width, int height);
void		loop_window(Tool *window);
void		init_windows(t_window_manager *wm);
void		add_event(Tool *widget, const char *event_name, GCallback callback);
void		add_to_fixed(GtkFixed *fixed, Tool *widget, gint x, gint y);
void		add_to_grid(GtkGrid *grid, Tool *widget, guint left,
			guint top, guint width, guint height);
void		apply_css(Tool *widget, const char *css);
void		set_button_color(Tool *button, const char *color);
void		set_label_color(Tool *label, const char *color);
void		set_entry_border_color(Tool *entry, const char *color);
Tool*		create_image(GtkFixed *fixed, const char *file_path, gint x, gint y);
Tool*		create_entry(GtkFixed *fixed, gint x, gint y);
void		add_tabs(Tool *notebook, Tool **pages, const char **titles, int count);
Tool*		create_text(GtkFixed *fixed, const char *text, gint x, gint y);
Tool*		create_button(GtkFixed *fixed, const char *label, gint x, gint y,
		void (*callback)(Tool *, gpointer), gpointer user_data);
void		show_notification(Tool *parent, const char *title, const char *message);
void		set_mouse_event_handler(Tool *widget,
			void (*handler)(GdkEventButton *, gpointer), gpointer user_data);
void		add_tab_to_notebook(Tool *notebook, const char *label, Tool *content);
void		set_key_event_handler(Tool *widget,
				void (*handler)(GdkEventKey *, gpointer), gpointer user_data);
void		set_loop_event_handler(guint interval, void (*handler)(gpointer), gpointer user_data);
void		reposition_widget_in_grid(GtkGrid *grid, Tool *widget, int left, int top);
void		set_status_bar_message(Tool *status_bar, const char *message);
void		color_activated(GtkColorChooser *chooser, gpointer user_data);
Tool	*create_image_c(Tool *container, const char *file_path);
Tool	*create_calendar(Tool *container);
Tool	*create_file_chooser_button(Tool *container, const char *title,
                                      GtkFileChooserAction action, GCallback callback, gpointer data);
Tool	*create_color_chooser(Tool *container, GCallback callback, gpointer data);
Tool	*create_notebook(Tool *container);
void		define_css(GtkWidget *widget);
Tool	*create_media_viewer(Tool *container);
Tool	*create_toolbar(Tool *container);
GtkToolItem	*create_toolbar_button(Tool *toolbar, const char *icon_name,
				const char *tooltip, GCallback callback, gpointer data);
Tool	*add_widget_at_position(Tool *fixed_container, Tool *widget, int x, int y);
Tool	*create_color_chooser_with_position(Tool *container, int x, int y,
				int width, int height, GdkRGBA *color);
void	sf_icon(GtkApplication *app, const char *icon_path);

#endif // LIBSF_H

