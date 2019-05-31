#include <list>

class Component {
private:
    typedef std::list<Component*> list_t;

    list_t internals_;
public:
    typedef list_t::iterator iterator;

    Component();
    ~Component();

    /** @brief Adds a component to the component.  The input pointer is set to
     *  a nullptr to prevent further modification of the component.
     *
     *  @attention This method invalidates the pointer passed into it.  This is
     *  because the Component class owns its contained components and all access
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
