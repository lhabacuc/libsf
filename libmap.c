#include "libsf.h"

unsigned int	hash(const char *key)
{
	unsigned int	hash;
	int				c;

	hash = 5381;
	while ((c = *key++))
		hash = ((hash << 5) + hash) + c;
	return (hash % MAP_SIZE);
}

void	map_init(t_map *map)
{
	int	i;

	i = 0;
	while (i < MAP_SIZE)
	{
		map->buckets[i] = NULL;
		i++;
	}
}

void	map_put(t_map *map, const char *key, const char *value)
{
	unsigned int	index;
	t_keyvalue		*entry;
	t_keyvalue		*new_entry;

	index = hash(key);
	entry = map->buckets[index];
	while (entry != NULL)
	{
		if (strcmp(entry->key, key) == 0)
		{
			free(entry->value);
			entry->value = strdup(value);
			return ;
		}
		entry = entry->next;
	}
	new_entry = malloc(sizeof(t_keyvalue));
	new_entry->key = strdup(key);
	new_entry->value = strdup(value);
	new_entry->next = map->buckets[index];
	map->buckets[index] = new_entry;
}

int	map_get(t_map *map, const char *key, char **value)
{
	unsigned int	index;
	t_keyvalue		*entry;

	index = hash(key);
	entry = map->buckets[index];
	while (entry != NULL)
	{
		if (strcmp(entry->key, key) == 0)
		{
			*value = strdup(entry->value);
			return (1);
		}
		entry = entry->next;
	}
	return (0);
}

void	map_remove(t_map *map, const char *key)
{
	unsigned int	index;
	t_keyvalue		*entry;
	t_keyvalue		*prev;

	index = hash(key);
	entry = map->buckets[index];
	prev = NULL;
	while (entry != NULL)
	{
		if (strcmp(entry->key, key) == 0)
		{
			if (prev == NULL)
				map->buckets[index] = entry->next;
			else
				prev->next = entry->next;
			free(entry->key);
			free(entry->value);
			free(entry);
			return ;
		}
		prev = entry;
		entry = entry->next;
	}
}

void	map_free(t_map *map)
{
	int			i;
	t_keyvalue	*entry;
	t_keyvalue	*next;

	i = 0;
	while (i < MAP_SIZE)
	{
		entry = map->buckets[i];
		while (entry != NULL)
		{
			next = entry->next;
			free(entry->key);
			free(entry->value);
			free(entry);
			entry = next;
		}
		i++;
	}
}

void	map_save_to_file(t_map *map, const char *filename)
{
	FILE		*file;
	t_keyvalue	*entry;
	int			i;

	file = fopen(filename, "w");
	if (file == NULL)
	{
		perror("Failed to open file for writing");
		return ;
	}
	i = 0;
	while (i < MAP_SIZE)
	{
		entry = map->buckets[i];
		while (entry != NULL)
		{
			fprintf(file, "%s=%s\n", entry->key, entry->value);
			entry = entry->next;
		}
		i++;
	}
	fclose(file);
}

void	map_load_from_file(t_map *map, const char *filename)
{
	FILE	*file;
	char	line[256];
	char	*key;
	char	*value;
	char	*delimiter;
	size_t	len;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		perror("Failed to open file for reading");
		return ;
	}
	while (fgets(line, sizeof(line), file))
	{
		delimiter = strchr(line, '=');
		if (delimiter != NULL)
		{
			*delimiter = '\0';
			key = strdup(line);
			value = strdup(delimiter + 1);
			len = strlen(value);
			if (value[len - 1] == '\n')
				value[len - 1] = '\0';
			map_put(map, key, value);
			free(key);
			free(value);
		}
	}
	fclose(file);
}
/*
int	main(void)
{
	t_map		map;
	char		*value;

	map_init(&map);
	map_put(&map, "ae", "frit");
	map_put(&map, "ct", "vegetable");
	map_put(&map, "appr", "fruit");
	map_put(&map, "carrt", "vegable");

	// Save the map to a file
	map_save_to_file(&map, FILE_NAME);

	// Free the map
	map_free(&map);

	// Reinitialize and load the map from the file
	map_init(&map);
	map_load_from_file(&map, FILE_NAME);

	// Retrieve and print values from the loaded map
	if (map_get(&map, "apple", &value))
	{
		printf("Value for 'apple': %s\n", value);
		free(value);
	}
	else
		printf("'apple' not found\n");

	if (map_get(&map, "carrot", &value))
	{
		printf("Value for 'carrot': %s\n", value);
		free(value);
	}
	else
		printf("'carrot' not found\n");

	// Free the map
	map_free(&map);

	return (0);
}
*/
