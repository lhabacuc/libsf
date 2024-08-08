# include "libsf.h"

void		add_or_update_record(const char *db_name, const char *key, const char *value, const char *arquivo);
void		create_directory(const char *path);
void		create_new_database(const char *db_name, const char *arquivo);
char		*get_value(const char *db_name, const char *key, const char *arquivo);
void		listar_registros(const char *db_name, const char *arquivo);
void		delete_record(const char *db_name, const char *key, const char *arquivo);

void	create_directory(const char *path)
{
	struct stat st = {0};

	if (stat(path, &st) == -1)
	{
		if (mkdir(path, 0700) != 0)
		{
			perror("Erro ao criar diretório");
			exit(EXIT_FAILURE);
		}
	}
}

void	create_new_database(const char *db_name, const char *arquivo)
{
	char db_path[256];
	snprintf(db_path, sizeof(db_path), "%s/%s", PUBLIC_DIR, db_name);

	create_directory(PUBLIC_DIR);
	create_directory(db_path);

	char file_path[256];
	snprintf(file_path, sizeof(file_path), "%s/%s/%s.db", PUBLIC_DIR, db_name, arquivo);
	FILE *file = fopen(file_path, "a+");
	if (file == NULL)
	{
		perror("Erro ao abrir o banco de dados");
		exit(EXIT_FAILURE);
	}
	fclose(file);
}

void	add_or_update_record(const char *db_name, const char *key, const char *value, const char *arquivo)
{
	char file_path[256];
	snprintf(file_path, sizeof(file_path), "%s/%s/%s.db", PUBLIC_DIR, db_name, arquivo);

	FILE *file = fopen(file_path, "r");
	FILE *temp_file = fopen(TEMP_FILE, "w");
	if (file == NULL)
	{
		perror("Erro ao abrir o banco de dados");
		exit(EXIT_FAILURE);
	}
	if (temp_file == NULL)
	{
		perror("Erro ao criar arquivo temporário");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	char line[MAX_LINE_LENGTH];
	int found = 0;

	while (fgets(line, sizeof(line), file))
	{
		char stored_key[MAX_KEY_LENGTH];
		sscanf(line, "%127s", stored_key);
		if (strcmp(stored_key, key) == 0)
		{
			fprintf(temp_file, "%s %s\n", key, value);
			found = 1;
		}
		else
			fprintf(temp_file, "%s", line);
	}

	if (!found)
	{
		fprintf(temp_file, "%s %s\n", key, value);
	}

	fclose(file);
	fclose(temp_file);

	if (remove(file_path) != 0 || rename(TEMP_FILE, file_path) != 0)
	{
		perror("Erro ao substituir o banco de dados");
		exit(EXIT_FAILURE);
	}
}

char	*get_value(const char *db_name, const char *key, const char *arquivo)
{
	static char value[MAX_VALUE_LENGTH];
	char file_path[256];
	snprintf(file_path, sizeof(file_path), "%s/%s/%s.db", PUBLIC_DIR, db_name, arquivo);

	FILE *file = fopen(file_path, "r");
	if (file == NULL)
	{
		perror("Erro ao abrir o banco de dados");
		return (NULL);
	}

	char line[MAX_LINE_LENGTH];
	while (fgets(line, sizeof(line), file))
	{
		char stored_key[MAX_KEY_LENGTH];
		char stored_value[MAX_VALUE_LENGTH];
		sscanf(line, "%127s %127[^\n]", stored_key, stored_value);
		if (strcmp(stored_key, key) == 0)
		{
			fclose(file);
			strncpy(value, stored_value, sizeof(value));
			return (value);
		}
	}

	fclose(file);
	return (NULL);
}

void	listar_registros(const char *db_name, const char *arquivo)
{
	char file_path[256];
	snprintf(file_path, sizeof(file_path), "%s/%s/%s.db", PUBLIC_DIR, db_name, arquivo);

	FILE *file = fopen(file_path, "r");
	if (file == NULL)
	{
		perror("Erro ao abrir o banco de dados");
		return;
	}

	char line[MAX_LINE_LENGTH];
	while (fgets(line, sizeof(line), file))
		printf("%s", line);

	fclose(file);
}

void	delete_record(const char *db_name, const char *key, const char *arquivo)
{
	char file_path[256];
	snprintf(file_path, sizeof(file_path), "%s/%s/%s.db", PUBLIC_DIR, db_name, arquivo);

	FILE *file = fopen(file_path, "r");
	FILE *temp_file = fopen(TEMP_FILE, "w");
	if (file == NULL)
	{
		perror("Erro ao abrir o banco de dados");
		exit(EXIT_FAILURE);
	}
	if (temp_file == NULL)
	{
		perror("Erro ao criar arquivo temporário");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	char line[MAX_LINE_LENGTH];
	int found = 0;

	while (fgets(line, sizeof(line), file))
	{
		char stored_key[MAX_KEY_LENGTH];
		sscanf(line, "%127s", stored_key);
		if (strcmp(stored_key, key) != 0)
			fprintf(temp_file, "%s", line);
		else
			found = 1;
	}

	if (!found)
		printf("Chave '%s' não encontrada.\n", key);
	fclose(file);
	fclose(temp_file);
	if (remove(file_path) != 0 || rename(TEMP_FILE, file_path) != 0)
	{
		perror("Erro ao substituir o banco de dados");
		exit(EXIT_FAILURE);
	}
}
