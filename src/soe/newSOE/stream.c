void initMap(Map *map)
{
    map->head = NULL;
}

void addToMap(Map *map, Node *newNode, i32 key, void *value)
{
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->head;
    map->head = newNode;
}

void *getFromMap(Map *map, int key)
{
    Node *current = map->head;

    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }

    return NULL;
}

void deleteFromMap(Map *map, int key)
{
    Node *current = map->head;
    Node *prev = NULL;

    while (current != NULL && current->key != key)
    {
        prev = current;
        current = current->next;
    }

    if (current != NULL)
    {
        if (prev != NULL)
        {
            prev->next = current->next;
        }
        else
        {
            map->head = current->next;
        }
        free(current);
    }
    else
    {
        printf("Key %d not found in the map.\n", key);
    }
}

void cleanupMap(Map *map)
{
    Node *current = map->head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    map->head = NULL;
}