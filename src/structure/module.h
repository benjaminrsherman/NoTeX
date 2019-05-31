#include <list>

class Component;

class Module {
private:
    typedef std::variant<Module*, Component*> internal_t;
    typedef std::list<internal_t> list_t;

    list_t internals_;
public:
    typedef list_t::iterator iterator;

    Module();
    ~Module();

    /** @brief Adds a module to the module.  The input pointer is set to a
     *  nullptr to prevent further modification of the module.
     *
     *  @attention This method invalidates the pointer passed into it.  This is
     *  because the Module class owns its contained modules and all access to
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
    
    /** @brief Adds a component to the module.  The input pointer is set to
     *  a nullptr to prevent further modification of the component.
     *
     *  @attention This method invalidates the pointer passed into it.  This is
     *  because the Module class owns its contained components and all access
     *  to components should be obtained via the API.
     *
     *  @param m   Pointer to the component to add.
     *  @param itr Optional pointer to a position in the list of components.
     *             If not given, this defaults to the end of the list.
     *  
     *  @returns Iterator to the inserted component
     */
    iterator AddComponent(Component*& m,
                          const iterator& itr = modules_.end());
};
