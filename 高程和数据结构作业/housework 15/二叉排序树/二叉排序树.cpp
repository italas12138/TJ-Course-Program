
#include <iostream>
using namespace std;

#define maxsize 1000005

int number[maxsize];

int main()
{
	int n, op, ch, min = 1000000;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> op;
		switch (op)
		{
			case 1:
				cin >> ch;
				++number[ch];
				if (ch < min)
					min = ch;
				break;
			case 2:
				cin >> ch;
				if (number[ch] == 0)
					cout << "None" << endl;
				else
				{
					--number[ch];
					if (ch == min && number[ch] == 0)
					{
						while (!number[ch])
							++ch;
						min = ch;
					}
				}
				break;
			case 3:
				cin >> ch;
				cout << number[ch] << endl;
				break;
			case 4:
				cout << min << endl;
				break;
			case 5:
				cin >> ch;		
				--ch;
				while (!number[ch] && ch != 0&&ch!=-1)
					--ch;
				if (ch == -1)
					cout << "None" << endl;
                else if(ch==0)
                    cout << "None" << endl;
				else
					cout << ch << endl;
				break;
			default:
					--i;

		}
	}

	return 0;
}


/*
#include <iostream>
using namespace std;


class SORTTREE {
public:
    struct NODE {
        NODE* left_, * right_, * parent_;
        int elem_, count_, height_;
        NODE(int elem, NODE* parent) : elem_(elem), parent_(parent) {
            left_ = NULL;
            right_ = NULL;
            count_ = 1;
            height_ = 1;
        }
        ~NODE() {
            if (left_)
                delete left_;
            if (right_)
                delete right_;
        }
  
        int Balance() {
            return -(left_ ? left_->height_ : 0) + (right_ ? right_->height_ : 0);
        }
 
        void UpdateHeight() {
            height_ = std::max((left_ ? left_->height_ : 0), (right_ ? right_->height_ : 0)) + 1;
        }

        bool Find(int elem, NODE*& last, NODE*& thiss, NODE*& next, bool& found) {
            if (left_)
                if (left_->Find(elem, last, thiss, next, found))
                    return true;
            if (found) { 
                next = this;
                return true;
            }
            if (elem_ > elem) { 
                thiss = NULL;
                next = this;
                return true;
            }
            if (elem_ == elem) { 
                thiss = this;
                found = true;
            }
            else
                last = this; 
            if (right_)
                return right_->Find(elem, last, thiss, next, found);
            return false; 
        }
    };

    SORTTREE() { root_ = NULL; }
    ~SORTTREE() { delete root_; }
    
    void Insert(int elem) {
        if (!root_) {
            root_ = new NODE(elem, NULL);
            return;
        }
        NODE* l = NULL, * p = NULL, * n = NULL;
        bool found = false;
        root_->Find(elem, l, p, n, found);

        if (p) {
            p->count_++;
            return;
        }
        
        if (l && !l->right_) {
            p = (l->right_ = new NODE(elem, l));
        }
        else {
            p = (n->left_ = new NODE(elem, n));
        }
        KeepBalance(p);
    }
    
    bool Delete(int elem) {
        if (!root_)
            return false;
        NODE* l = NULL, * p = NULL, * n = NULL;
        bool found = false;
        root_->Find(elem, l, p, n, found);
        if (!p) 
            return false;
        if (p->count_ > 1) { 
            p->count_--;
            return true;
        }
       
        if (!p->left_ && !p->right_) {
            if (!p->parent_) {
                root_ = NULL;
            }
            else {
                ChangeParent(p, NULL);
                KeepBalance(p->parent_);
            }
        }
        else if (!p->left_) { 
            ChangeParent(p, p->right_);
            KeepBalance(p->parent_);
        }
        else { 
            if (p->left_ == l) { 
                l->right_ = p->right_;
                if (p->right_)
                    p->right_->parent_ = l;
                ChangeParent(p, l);
                KeepBalance(l);
            }
            else {
                NODE* t = l->parent_;
                t->right_ = l->left_;
                if (l->left_)
                    l->left_->parent_ = t;

                l->left_ = p->left_;
                p->left_->parent_ = l;
                l->right_ = p->right_;
                if (p->right_)
                    p->right_->parent_ = l;
                ChangeParent(p, l);
                KeepBalance(t);
            }
        }
        p->left_ = p->right_ = NULL;
        delete p;
        return true;
    }

    int Count(int elem) {
        if (!root_)
            return 0;
        NODE* l = NULL, * p = NULL, * n = NULL;
        bool found = false;
        root_->Find(elem, l, p, n, found);
        if (p)
            return p->count_;
        return 0;
    }
 
    int FindMinElem() {
        if (!root_)
            return -1;
        NODE* p = root_;
        while (p->left_)
            p = p->left_;
        return p->elem_;
    }

    int FindFrontElem(int elem) {
        if (!root_)
            return -1;
        NODE* l = NULL, * p = NULL, * n = NULL;
        bool found = false;

        root_->Find(elem, l, p, n, found);
        if (l)
            return l->elem_;
        return -1;
    }
private:

    void KeepBalance(NODE* p) {
        while (p) {
            p->UpdateHeight();
            if (-2 >= p->Balance() || p->Balance() >= 2) {
         
                if (p->Balance() < 0) {
                    if (p->left_->Balance() <= 0) {
                        RotateRight(p);
                    }
                    else {
                        RotateLeft(p->left_);
                        RotateRight(p);
                    }
                }
                else {
                    if (p->right_->Balance() >= 0) {
                        RotateLeft(p);
                    }
                    else {
                        RotateRight(p->right_);
                        RotateLeft(p);

                    }
                }
            }
            p = p->parent_;
        }
    }
   
    void RotateRight(NODE* p) {
        NODE* t = p->left_;
        p->left_ = t->right_;
        if (t->right_)
            t->right_->parent_ = p;
        t->right_ = p;
        UpdateRelation(p, t);
    }

    void RotateLeft(NODE* p) {
        NODE* t = p->right_;
        p->right_ = t->left_;
        if (t->left_)
            t->left_->parent_ = p;
        t->left_ = p;
        UpdateRelation(p, t);
    }
  
    void UpdateRelation(NODE* p, NODE* t) {
        ChangeParent(p, t);
        p->parent_ = t;
        p->UpdateHeight();
        t->UpdateHeight();
    }

    void ChangeParent(NODE* p, NODE* t) {
        if (t)
            t->parent_ = p->parent_;
        if (p->parent_) {
            if (p == p->parent_->left_)
                p->parent_->left_ = t;
            else
                p->parent_->right_ = t;
        }
        else
            root_ = t;
    }
    NODE* root_;
};

int main()
{
    int n;
    SORTTREE& T = *(new SORTTREE);
    std::cin >> n;
    while (n--) {
        int ope, elem = 0, last = 0;
        std::cin >> ope;
        if (ope != 4)
            std::cin >> elem;
        switch (ope) {
            case 1:
                T.Insert(elem);
                break;
            case 2:
                if (!T.Delete(elem))
                    std::cout << "None" << std::endl;
                break;
            case 3:
                std::cout << T.Count(elem) << std::endl;
                break;
            case 4:
                std::cout << T.FindMinElem() << std::endl;
                break;
            case 5:
                last = T.FindFrontElem(elem);
                if (last == -1)
                    std::cout << "None" << std::endl;
                else
                    std::cout << last << std::endl;
                break;
            default:
                break;
        }
    }
    delete& T;
    return 0;
}
*/