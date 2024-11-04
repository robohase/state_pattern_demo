# state_pattern_demo
state_pattern_demoをROS2で実装するためのデモ

# 環境
Ubuntu 22.04
ROS 2 Humble

# インストール
```bash
cd ~/ros2_ws/src
git clone git@github.com:robohase/state_pattern_demo.git
cd ~/ros2_ws
rosdep install -r -y -i --from-paths .
```

# ビルド
```bash
cd ~/ros2_ws/src
colcon build --symlink-install
```

# 実行
