#include "tagspec.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

#include "strutil.h"

//creates a new tagcmp
tagcmp_t *tagcmp_new(const char *name, const char *value, tagcmp_kind_t kind) {
    tagcmp_t *cmp = malloc(sizeof(tagcmp_t));

    cmp->name = strdup(name);
    cmp->value = strdup(value);
    cmp->kind = kind;
    cmp->next = NULL;

    return cmp;
}

//creates a new list that stores the tag order
tagorder_t *tagorder_new(const char *name) {
    tagorder_t *tag = malloc(sizeof(tagorder_t));

    tag->name = strdup(name);
    tag->next = NULL;

    return tag;
}

//frees the tag order
void tagorder_free(tagorder_t *tag) {
    if (tag == NULL)
        return;

    tagorder_free(tag->next);
    free(tag->name);
    free(tag);
}

//adds to the tagspec
void tagspec_add(tagspec_t *spec, const char *name, const char *value,
                 tagcmp_kind_t kind) {
    if (kind != TAG_ALWAYS) {
        tagcmp_t *cmp = tagcmp_new(name, value, kind);

        if (spec->head == NULL) {
            spec->head = cmp;
            spec->tail = cmp;
        } else {
            spec->tail->next = cmp;
            spec->tail = spec->tail->next;
        }
    }

    tagorder_t *tag = tagorder_new(name);

    if (spec->order_head == NULL) {
        spec->order_head = tag;
        spec->order_tail = tag;
    } else {
        spec->order_tail->next = tag;
        spec->order_tail = spec->order_tail->next;
    }
}

//creates a new tagspec
tagspec_t *tagspec_new(void) {
    tagspec_t *tags = malloc(sizeof(tagspec_t));

    tags->head = NULL;
    tags->tail = NULL;

    tags->order_head = NULL;
    tags->order_tail = NULL;

    return tags;
}

//frees all the tagcmps
void tagcmp_free(tagcmp_t *cmp) {
    while (cmp != NULL) {
        tagcmp_t *next = cmp->next;

        free(cmp->name);
        free(cmp->value);
        free(cmp);

        cmp = next;
    }
}

//frees the tagspecs
void tagspec_free(tagspec_t *spec) {
    if (spec == NULL)
        return;

    tagcmp_free(spec->head);
    tagorder_free(spec->order_head);

    free(spec);
}

//get the king of tagspec
tagcmp_kind_t tagspec_get_kind(char opperator) {
    switch (opperator) {
        case '!':
            return TAG_NOT_EQUALS;
        case '=':
            return TAG_EQUALS;
        case '-':
            return TAG_NOT_CONTAINS;
        case '~':
            return TAG_CONTAINS;
        case '>':
            return TAG_GREATER_THAN;
    }

    return TAG_UNKNOWN_CMP;
}

//returns true if name of the tagspec isn't empty
bool tagspec_parse_line(tagspec_t *spec, const char *line) {

    //I recommend making the calloc byte count a macro constant, it's better for readability 
    char *name = calloc(200, 1);
    char *value = calloc(200, 1);
    char *cmp = calloc(20, 1);

    sscanf(line, "%[^\t\n ] %[^\t\n ] %[^\n]", name, cmp, value);

    bool success = false;
    if (name[0] != '\0' && value[0] != '\0') {
        tagcmp_kind_t kind = tagspec_get_kind(cmp[0]);
        if (kind != TAG_UNKNOWN_CMP) {
            tagspec_add(spec, name, value, kind);
            success = true;
        }
    } else if (name[0] != '\0') {
        tagspec_add(spec, name, NULL, TAG_ALWAYS);
        success = true;
    }

    free(name);
    free(value);
    free(cmp);

    return success;
}

/*gets and checks all the tagpsecs in a file, I will say that this should probably have a bool
return value as to determine if a file is valid or not
*/
void tagspec_load(tagspec_t *spec, FILE *spec_fp) {
    char *line = NULL;
    size_t line_len;
    while (getline(&line, &line_len, spec_fp) != -1)
        assert(tagspec_parse_line(spec, line));

    free(line);
}

//checks if a tagspec matches
bool tagspec_matches(tagspec_t *spec, const char *name, const char *value) {
    for (tagcmp_t *cmp = spec->head; cmp != NULL; cmp = cmp->next) {
        if (strcmp(name, cmp->name) != 0)
            continue;

        switch (cmp->kind) {
            case TAG_EQUALS:
                return strcmp(value, cmp->value) == 0;
            case TAG_NOT_EQUALS:
                return strcmp(value, cmp->value) != 0;
            case TAG_CONTAINS:
                return strstr(value, cmp->value) != NULL;
            case TAG_NOT_CONTAINS:
                return strstr(value, cmp->value) == NULL;
            case TAG_GREATER_THAN:
                return atoi(value) > atoi(cmp->value);
            case TAG_ALWAYS:
                return true;
            default:
                fprintf(stderr, "Unknown operator: %c", cmp->kind);
                assert(false && "unimplemented");
        }
    }

    return true;
}
