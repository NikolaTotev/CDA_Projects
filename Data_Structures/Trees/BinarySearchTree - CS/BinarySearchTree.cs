using System;
using System.Collections.Generic;
using System.Runtime.InteropServices.ComTypes;
using System.Text;
using System.Threading;

namespace BinarySearchTree___CS
{
    public class TreeNode
    {
        private int data;
        private TreeNode leftChild;
        private TreeNode rightChild;

        public TreeNode RightChild
        {
            get { return rightChild; }
            set { rightChild = value; }
        }


        public TreeNode LeftChild
        {
            get { return leftChild; }
            set { leftChild = value; }
        }

        public int Data
        {
            get { return data; }
            set { data = value; }
        }

        public TreeNode(int data)
        {
            Data = data;
        }

        public TreeNode(TreeNode oldNode)
        {
            Data = oldNode.Data;
            LeftChild = new TreeNode(oldNode.LeftChild);
            RightChild = new TreeNode(oldNode.RightChild);
        }

        public override bool Equals(object obj)
        {
            return base.Equals(obj);
        }
    }
    public class BinarySearchTree
    {
    }
}
