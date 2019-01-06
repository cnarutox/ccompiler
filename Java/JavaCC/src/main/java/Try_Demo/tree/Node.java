package Try_Demo.tree;

import java.util.ArrayList;

public class Node {
    public static final Node NullNode = new Node(null);
    protected Node parent;
    protected ArrayList<Node> children;
    protected String type;
    protected Object value;
    protected int id;
    protected static int ID = 0;

    public Node(String type) {
        this.id = ID++;
        this.type = type;
        this.value = null;
        this.parent = null;
        this.children = new ArrayList<>();
    }

    public Node(String type, Object value) {
        this(type);
        this.value = value;
    }

    public Node(String type, Object value, Node... children) {
        this(type, value);
        for (Node child : children) {
            addChildren(child);
        }
    }

    public Node addChildren(Node... nodes) {
        for (Node node : nodes) {
            if (node != null) {
                node.parent = this;
                children.add(node);
            }
        }
        return this;
    }

    public void dump() {
        StringBuilder childrenId = new StringBuilder();
        for (Node child : children) {
            if (child != null) {
                childrenId.append(child.id);
                childrenId.append(' ');
            }
        }
        System.out.printf("%3s: %-10s   %-15s    Children: %s\n",
                id, type, value, childrenId);
        for (Node child : children) {
            if (child != null) {
                child.dump();
            }
        }
    }

    /**
     * 节点最简化
     *
     * @return
     */
    public Node simplify() {
        if (children.size() == 0) {
            return null;
        } else if (children.size() == 1) {
            return children.get(0);
        } else {
            return this;
        }
    }

    @Override
    public String toString() {
        return "Node{" +
                "parent=" + parent +
                ", children=" + children +
                ", type='" + type + '\'' +
                ", value=" + value +
                ", id=" + id +
                '}';
    }

    public String typeString() {
        StringBuilder buf = new StringBuilder();
        buf.append(type);
        for (int i = 0; i < children.size(); i++) {
//            if (!children.get(i).typeEquals(node.children.get(i))) {
//                return false;
//            }
        }
        return buf.toString();
    }

    public boolean typeEquals(Node node) {
        if (!type.equalsIgnoreCase(node.type)
                || children.size() != node.children.size()) {
            return false;
        }
        for (int i = 0; i < children.size(); i++) {
            if (!children.get(i).typeEquals(node.children.get(i))) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Node node = new Node("1");
        node.dump();
    }
}
