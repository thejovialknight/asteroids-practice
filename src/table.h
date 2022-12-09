#pragma once
#include <vector>

// The design is this: You have a list of values (values) and a list of integers (references) which 
// reference the index of those values.
// The reference indices are what is returned by the table.add() function, so they need to be updated
// when the location of values changes, or they will point to different data.
// When you remove from a list, both the values and references list changes.
// On the values list, the value pointed to by the reference index is replaced by the last value in
// the values list and then the vector is shrunk by one.
// On the references list, the final value we've just moved needs to have its associated ref_index int 
// value changed to 
//
// Special container for a list of data which can be easily added to and removed from, with the holes
// left behind by removal of elements being kept track of and filled back in by addition of elements.
// These are used in a database of data held by the game structure to represent cross cutting concerns 
// and shared data types between entities.
//
// For example, different types of entities might require the same type of data to be used by some external 
// system. Putting these in a table decouples the data from the systems that need to work over that data, 
// as in the case of both tiles and the player having physics, position, and sprite components, and there 
// being other entity types that use arbitrary sets of these components, such as a non interactable
// graphical effect only needing a position and sprite component, or a text box only needing a position,
// with the text being represented by the entity itself or by a text component.
//
// For another, different data structures like the above case used by the same entity might both need 
// access to the same component, such as both the physics and sprite components needing access to the 
// position component of an entity.
//
// This is similar to an ECS design architecture, but with the pro of being more flexible in data 
// representation. This has the cost of an at times unergonomic coding process, but I think the cleanliness
// and flexibility of this approach more than makes up for the increased time actually writing code.
template <typename T>
struct Table {
	std::vector<T> values; // Underlying list structure that holds all the data. Might have holes which contain invalid data, so need to makes checks for that for now.
	std::vector<int> references; // To be referenced by the at function. Contains indexes to the values list.
	std::vector<int> open_reference_indices;

	// Still confusing that this fucks things up.
	// Adds the element of type T to the table. Returns an index to be used with the at() function.
	int add(T value) {
		values.push_back(value);

		int return_index = 0;
		if(open_reference_indices.size() > 0) {
			return_index = open_reference_indices.back();
			references[return_index] = values.size() - 1;
			open_reference_indices.pop_back();
		}
		else {
			references.push_back(values.size() - 1);
			return_index = references.size() - 1;
		}

		return return_index;
	}

	// Refs are not getting redirected correctly.
	// Removes the element at ref_index from the table.
	void remove(int ref_index) {
		int index_to_value = references[ref_index];
		// If we are NOT removing the last item in the value list.
		if(index_to_value != values.size() - 1) {
			//T back_value = values.back();

			values[index_to_value] = values.back(); // Move back element to the newly open location.

			// Set reference int to the new position.
			for(int i = 0; i < references.size(); i++) {
				if(references[i] == values.size() - 1) {
					references[i] = index_to_value;
				}
			}
		}

		values.pop_back();

		open_reference_indices.push_back(ref_index);
	}

	// Returns the element at a given index of the table.
	T& at(int ref_index) {
		return values[references[ref_index]];
	}

	// Returns the number of elements in the table.
	int size() {
		return values.size();
	};

	// Resets the table to its starting situation.
	void clear() {
		values.clear();
		references.clear();
		open_reference_indices.clear();
	}
};
