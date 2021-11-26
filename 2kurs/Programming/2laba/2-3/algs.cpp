//
// Created by arseniy on 26.11.2021.
//

// Pre
//TreeIterator& operator++()
//{
//    if(ptr->getRight())
//    {
//        ptr = ptr->getRight();
//        while(ptr->getLeft() != nullptr)
//        {
//            ptr = ptr->getLeft();
//        }
//    }
//    else
//    {
//        Node<ValueType>* before;
//        do{
//            before = ptr;
//            ptr = ptr->getParent();
//        }while(ptr != nullptr && before == ptr->getRight());
//    }
//    return *this;

//        Node<ValueType>* p;
//        if(ptr == nullptr)
//        {//ptr = ptr.getleft
//            if(ptr == nullptr) while(ptr->getLeft() != nullptr) ptr = ptr->getLeft();
//        }
//        else if(ptr->getRight() != nullptr){ ptr = ptr->getRight(); while(ptr->getLeft() != nullptr) ptr = ptr->getLeft(); }
//        else
//        {
//            p = ptr->getParent();
//            while(p != nullptr && ptr == p->getRight()){ ptr = p; p = p->getParent(); }
//            ptr = p;
//        }
//        return *this;
//}

// Post
//TreeIterator& operator++(int v)
//{
//    TreeIterator<ValueType> old(*this);
//    ++(*this);
//    return old;
//        if(!ptr) return *this;
//        else {
//            Node<ValueType> *p;
//            auto *temp = new TreeIterator<ValueType>(ptr);
//            if (ptr == nullptr) { while (ptr->getLeft() != nullptr) ptr = ptr->getLeft(); }
//            else if (ptr->getRight() != nullptr) {
//                ptr = ptr->getRight();
//                while (ptr->getLeft() != nullptr) ptr = ptr->getLeft();
//            }
//            else {
//                p = ptr->getParent();
//                while (p != nullptr && ptr == p->getRight()) {
//                    ptr = p;
//                    p = p->getParent();
//                }
//                ptr = p;
//            }
//            return *temp;
//        }
//}