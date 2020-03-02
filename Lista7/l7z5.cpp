#include<iostream>


class UnionFind 
    {
        public:
            UnionFind(int n) : m_parent{new int[n]}, m_rank{new int[n]}
            {
                for(int i = 0; i < n; ++i)
                {
                    m_parent[i] = i;
                    m_rank[i] = 0;
                }
            }
            int Find(int i) // Find jest to kompresja ścieżki.
            {
                if(m_parent[i] == i) // znajdź korzeń
                    return i;
                return m_parent[i] = Find(m_parent[i]); // zrób korzeń parentem i.
            }
            void Union(int i,int j)
            {
                int a = Find(i);    // przypisujemy pod 'a' pierwszego reprezentatna 
                int b = Find(j);    // przypisujemy pod 'b' drugiego reprezentatna 
                if(a!=b)            // jesli reprezentanci są różni. 
                    if(m_rank[a] < m_rank[b])   // jeśli ranga reprezentanta a jest wieksza od rangi rep. b
                        m_parent[a] = b;        // łączymy wyspę a do wyspy b
                    else if(m_rank[b] < m_rank[a])
                        m_parent[b] = a;
                    else // jesli rangi reprezentantów są takie same
                    {
                        m_parent[a] = b;    // łączymy wyspę a do wyspy b
                        ++m_rank[b];        // zwiększamy rangę b
                    }
            }
            ~UnionFind()
            {
                delete[] m_rank;
                delete[] m_parent;
            }
        private:
            int* m_parent;
            int* m_rank;
    };

    int main(){
        
        return 0;
    }