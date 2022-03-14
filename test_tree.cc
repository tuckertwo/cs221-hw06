#define CATCH_CONFIG_MAIN 
#include "catch.hh"
#include "tree.hh"

// These test cases were based on the specification given in `tree.hh`.
tree_ptr_t leaf    = create_tree(16, 65536);
tree_ptr_t sequoia = create_tree(154, 65536,
        create_tree(0, 1, create_tree(1, 2, create_tree(2, 4, nullptr, leaf))),
        create_tree(4, 7, create_tree(8, 256), create_tree(7, 128)));
TEST_CASE("Creating trees")
{
  REQUIRE(leaf);
  REQUIRE(leaf->key_   == 16);
  REQUIRE(leaf->value_ == 65536);
  REQUIRE(leaf->left_  == nullptr);
  REQUIRE(leaf->right_ == nullptr);
  REQUIRE(sequoia);
  REQUIRE(sequoia->key_   == 154);
  REQUIRE(sequoia->value_ == 65536);
  REQUIRE(sequoia->left_->left_->left_);
  REQUIRE(sequoia->left_->left_->left_->key_     == 2);
  REQUIRE(sequoia->left_->left_->left_->left_    == nullptr);
  REQUIRE(sequoia->left_->left_->left_->right_   == leaf);
}

TEST_CASE("Tree traversal functions")
{
  REQUIRE(path_to(nullptr, 10) == "-");
  REQUIRE(node_at(nullptr, "LRLRLRLR") == nullptr);
  REQUIRE(path_to(leaf, 16) == "");
  REQUIRE(path_to(leaf, 32) == "-");
  REQUIRE(path_to(sequoia, 32) == "-");
  REQUIRE(path_to(sequoia, 154) == "");
  REQUIRE(path_to(sequoia, 16) == "LLLR");
  REQUIRE(node_at(sequoia, "") == sequoia);
  REQUIRE(node_at(sequoia, path_to(sequoia, 154)) == sequoia);
  REQUIRE(node_at(sequoia, path_to(sequoia, 16))  == leaf);
}

TEST_CASE("The lumberjack")
{
  destroy_tree(sequoia);
}
