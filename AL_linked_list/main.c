/**
 * @file main.c
 * @author Lukas Verwiebe
 * @brief 
 * @version 0.1
 * @date 2023-10-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>


/**
 * @brief 
 * Eintrag für Linked List
 */
struct ENTRY
{
	int value;
	struct ENTRY *next;
	struct ENTRY *prev;
};


/**
 * @brief 
 * Eintrag in die Linked List einfügen
 * @param entry 
 * @param push_entry 
 */
void entry_push(struct ENTRY *entry, struct ENTRY *push_entry)
{
	if(entry != NULL && push_entry != NULL)
	{
		// Zwischenspeichern der bisherigen Angaben:
		struct ENTRY *entry_next = entry->next;
		struct ENTRY *entry_prev = entry->next->prev;

		// Angabe next in entry Ändern:
		entry->next = push_entry;
		// Angabe prev im bisherigen next Ändern
		entry_next->prev = push_entry;

		// Angaben in push Ändern:
		push_entry->prev = entry;
		push_entry->next = entry_next;

		// Speicher freigeben:
		//free(entry_next);
		entry_next = NULL;
		//free(entry_prev);
		entry_prev = NULL;

	}
}


/**
 * @brief 
 * Eintag aus der Linked List entfernen
 * @param pop_entry 
 */
void entry_pop(struct ENTRY *pop_entry)
{
	if(pop_entry != NULL)
	{
		// Zwischenspeichern der bisherigen Angaben:
		struct ENTRY *pop_next = pop_entry->next;
		struct ENTRY *pop_prev = pop_entry->prev;

		// Angaben in prev Ändern:
		pop_prev->next = pop_next;

		// Angaben in next Ändern:
		pop_next->prev = pop_prev;

		// Angaben in pop löschen:
		pop_entry->value = 0;
		pop_entry->next = NULL;
		pop_entry->prev = NULL;

		// Speicher freigeben:
		//free(pop_entry);
		pop_entry = NULL;
	}
}



/**
 * @brief 
 * Linked List Eintrag
 */
typedef struct ENTRY_2
{
	int value;
	struct ENTRY_2 *next;
	struct ENTRY_2 *prev;
} ENTRY2;


/**
 * @brief 
 * Linked List
 */
typedef struct LINKED_LIST_2
{
	ENTRY2 *first;
	ENTRY2 *last;
	int size;
} LINKEDLIST;


/**
 * @brief 
 * Neuen Eintrag in die Linked List einfügen
 * @param entry 
 * @param list_entry 
 */
void list_push(ENTRY2 *entry, LINKEDLIST *list_entry)
{
	if(entry != NULL)
	{
		// Last Entry zwischenspeichern:
		ENTRY2 *list_last = list_entry->last;

		// Linkedlist Ändern:
		list_entry->last = entry;
		list_entry->size = list_entry->size + 1;

		// Neuen Last Entry setzten:
		list_last->next = entry;
		entry->prev = list_last;
	}
}


/**
 * @brief 
 * Eintrag aus der Linked List entfernen
 * @param entry 
 */
void list_pop(ENTRY2 *entry)
{
	ENTRY2 *prev_entry = entry;
	if(entry != NULL && entry->next != NULL)
	{
		while(prev_entry->prev != NULL)
		{
			prev_entry = prev_entry->prev;
		}
	}

	printf("Test: %d\n", prev_entry->value);
	prev_entry->next->prev = NULL;
	prev_entry->next = NULL;
	prev_entry->value = 0;
}


/**
 * @brief 
 * Linked List Rückwärts Sortieren
 * @param entry 
 */
void sort_back(ENTRY2 *entry)
{
	ENTRY2 *last_entry = entry;
	if(entry != NULL)
	{
		while(last_entry->next != NULL)
		{
			last_entry = last_entry->next;
		}
	}

	while(last_entry->prev != NULL)
	{
		last_entry->prev = last_entry->next->prev;
		last_entry->next = last_entry->prev;
	}
}



/**
 * @brief 
 * Test Funktion
 * @return int 
 */
int main(void)
{
    // Test ENTRY
    struct ENTRY test1;
	struct ENTRY test2;
	struct ENTRY test3;

	test1.value = 1;
	test2.value = 2;
	test3.value = 3;

	test1.next = &test2;
	test2.next = &test3;
	test2.prev = &test1;
	test3.prev = &test2;

	struct ENTRY test4;
	test4.value = 4;
	entry_push(&test1, &test4);

	printf("Ergebnis Push: \n");
	printf("Eintrag 1: %d\n", test1.value);
	printf("Eintrag 1 next: %d\n", test1.next->value);
	printf("\n");

	printf("Eintrag 2: %d\n", test2.value);
	printf("Eintrag 2 next: %d\n", test2.next->value);
	printf("Eintrag 2 prev: %d\n", test2.prev->value);
	printf("\n");

	printf("Eintrag 3: %d\n", test3.value);
	printf("Eintrag 3 prev: %d\n", test3.prev->value);
	printf("\n");

	printf("Eintrag 4: %d\n", test4.value);
	printf("Eintrag 4 next: %d\n", test4.next->value);
	printf("Eintrag 4 prev: %d\n", test4.prev->value);
	printf("\n");

	entry_pop(&test4);

	printf("Ergebnis Pop \n");
	printf("Eintrag 1: %d\n", test1.value);
	printf("Eintrag 1 next: %d\n", test1.next->value);
	printf("\n");

	printf("Eintrag 2: %d\n", test2.value);
	printf("Eintrag 2 next: %d\n", test2.next->value);
	printf("Eintrag 2 prev: %d\n", test2.prev->value);
	printf("\n");

	printf("Eintrag 3: %d\n", test3.value);
	printf("Eintrag 3 prev: %d\n", test3.prev->value);
	printf("\n");

	printf("Eintrag 4: %d\n", test4.value);
	//printf("Eintrag 4 next: %d\n", test4.next->value);
	//printf("Eintrag 4 prev: %d\n", test4.prev->value);
	printf("\n");


    // Test ENTRY2
    ENTRY2 etest1;
	ENTRY2 etest2;
	ENTRY2 etest3;

	etest1.value = 1;
	etest2.value = 2;
	etest3.value = 3;

	etest1.next = &etest2;
	etest2.next = &etest3;
	etest2.prev = &etest1;
	etest3.prev = &etest2;

	list_pop(&etest2);

	printf("Ergebnis POP: \n");
	printf("Eintrag 1: %d\n", etest1.value);
	printf("Eintrag 1 next: %d\n", etest1.next->value);
	printf("\n");

	printf("Eintrag 2: %d\n", etest2.value);
	printf("Eintrag 2 next: %d\n", etest2.next->value);
	printf("Eintrag 2 prev: %d\n", etest2.prev->value);
	printf("\n");

	printf("Eintrag 3: %d\n", etest3.value);
	printf("Eintrag 3 prev: %d\n", etest3.prev->value);
	printf("\n");
}