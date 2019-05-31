#include <list>

class Module;

class Document {
private:
    typedef std::list<Module*> mod_list;

		mod_list modules_;

public:
    typedef mod_list::const_iterator iterator;

    Document();
    ~Document();

    /** @brief Adds a module to the document.  The input pointer is set to a
     *  nullptr to prevent further modification of the module.
		 *
     *  @attention This method invalidates the pointer passed into it.  This is
		 *  because the Document class owns its contained modules and all access to
		 *  modules should be obtained via the API.
		 *
     *  @param m   Pointer to the module to add.
     *  @param itr Optional pointer to a position in the list of modules.  If
		 *             not given, this defaults to the end of the list.
     *  
		 *  @return Iterator to the inserted module
     */
    iterator AddModule(Module*& m,
                       const iterator& itr = modules_.end());
};
