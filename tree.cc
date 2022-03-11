#include "tree.hh"

//////////////////////////////////////////////////////////////////////////////
tree_ptr_t create_tree(const key_type& key,
            const value_type& value,
            tree_ptr_t left,
            tree_ptr_t right)
{
}


//////////////////////////////////////////////////////////////////////////////
void destroy_tree(tree_ptr_t tree)
{
  // This for loop can be confusing; the tree traversal is done recursively.
  // (The for loop is just here to iterate over the left and right nodes to
  // eliminate some cut-and-pasting of code.)
  for(tree_ptr_t branch : {tree->left_, tree->right_})
  {
    if(branch)
    {
      destroy_tree(branch);
    }
  }

  delete tree;
}


//////////////////////////////////////////////////////////////////////////////
std::string path_to(tree_ptr_t tree, key_type key)
{
}


//////////////////////////////////////////////////////////////////////////////
tree_ptr_t node_at(tree_ptr_t tree, std::string path)
{
}
