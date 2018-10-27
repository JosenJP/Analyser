#ifndef POINTER_HELPER_HPP
#define POINTER_HELPER_HPP

template<typename T>
void DeleteObject(T* a_pObject)
{
    if (NULL != a_pObject)
    {
        delete a_pObject;
        a_pObject = NULL;
    }
}

#endif // !POINTER_HELPER_HPP


