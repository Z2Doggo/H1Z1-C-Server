typedef struct GridCell {
    f32 position[4];
    BaseEntity* objects[KB(10)]; // keep like this until something breaks :P
    i32 width;
    i32 height;
} GridCell;

GridCell* GridConstruct(f32 x, f32 y, i32 width, i32 height) {
    GridCell* gridcell = malloc(sizeof(GridCell));
    if (!gridcell) {
        fprintf(stderr, "Failed to allocate memory to GridCell struct in GridConstruct function!\n");

        return NULL;
    }

    gridcell->position[0] = x;
    gridcell->position[1] = 0.0f;
    gridcell->position[2] = y;
    gridcell->position[3] = 1.0f;

    gridcell->width = width;
    gridcell->height = height;

    return gridcell;
}
