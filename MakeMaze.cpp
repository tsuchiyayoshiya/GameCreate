#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <iostream>
#include <fstream>
#include "MakeMaze.h"

namespace maze {

    using vsize_t = std::vector<size_t>;
    using vvsize_t = std::vector<vsize_t>;

    //�����`�F�b�N
    const bool mapCheck(const vvsize_t& map_) {
        if (map_.size() <= 2 || map_.data()->size() <= 2) return false;
        if ((map_.size() & 1) == 0 || (map_.data()->size() & 1) == 0) return false;
        return true;
    }
    //���@��
    void mazeDig(vvsize_t& map_, size_t x_, size_t y_, const size_t id_wall_, const size_t id_empty_)
    {
        if (!mapCheck(map_)) return;
        int32_t dx, dy;
        size_t random = size_t(rand()), counter = 0;
        while (counter < 4) {
            switch ((random + counter) & 3)
            {
            case 0:dx = 0; dy = -2; break;
            case 1:dx = -2; dy = 0; break;
            case 2:dx = 0; dy = 2; break;
            case 3:dx = 2; dy = 0; break;
            default:dx = 0; dy = 0; break;
            }
            if (x_ + dx <= 0 || y_ + dy <= 0 || x_ + dx >= map_.size() - 1 || y_ + dy >= map_.data()->size() - 1 || map_[x_ + dx][y_ + dy] == id_empty_) {
                ++counter;
            }
            else if (map_[x_ + dx][y_ + dy] == id_wall_) {
                map_[x_ + (dx >> 1)][y_ + (dy >> 1)] = id_empty_;
                map_[x_ + dx][y_ + dy] = id_empty_;
                x_ += dx;
                y_ += dy;
                counter = 0;
                random = size_t(rand());
            }
        }
        return;
    }
    //�o�H�T��
    void mazeRootLoop(vvsize_t& map_, const size_t x_, const size_t y_, const size_t id_empty_, const size_t id_root_)
    {
        //�o�H�T����
        static bool b = true;

        map_[x_][y_] = id_root_;
        if (x_ == map_.size() - 2 && y_ == map_.data()->size() - 2) b = false;
        //��
        if (b && map_[x_][y_ - 1] == id_empty_) mazeRootLoop(map_, x_, y_ - 1, id_empty_, id_root_);
        //��
        if (b && map_[x_][y_ + 1] == id_empty_) mazeRootLoop(map_, x_, y_ + 1, id_empty_, id_root_);
        //��
        if (b && map_[x_ - 1][y_] == id_empty_) mazeRootLoop(map_, x_ - 1, y_, id_empty_, id_root_);
        //�E
        if (b && map_[x_ + 1][y_] == id_empty_) mazeRootLoop(map_, x_ + 1, y_, id_empty_, id_root_);

        if (b) map_[x_][y_] = id_empty_;
        return;
    }
    void mazeRoot(vvsize_t& map_, const size_t id_empty_, const size_t id_root_)
    {
        if (!mapCheck(map_)) return;
        mazeRootLoop(map_, 1, 1, id_empty_, id_root_);
    }
    //�o��
    void mazeOutput(const vvsize_t& map_, const size_t id_wall_, const size_t id_empty_)
    {
        if (!mapCheck(map_)) return;
        const size_t i_max = map_.size();
        const size_t j_max = map_.data()->size();
        for (size_t i = 0; i < i_max; ++i) {
            for (size_t j = 0; j < j_max; ++j) {
                if (map_[i][j] == id_empty_) std::cout << "1";
                else if (map_[i][j] == id_wall_) std::cout << "0";
                else std::cout << "1";
            }
            std::cout << std::endl;
        }
    }
    //���H����
    const size_t mazeMakeLoop(vvsize_t& map_, const size_t id_wall_, const size_t id_empty_, std::unique_ptr<size_t[]>& select_x, std::unique_ptr<size_t[]>& select_y)
    {
        size_t ii = 0;
        const size_t i_max = map_.size() - 1;
        const size_t j_max = map_.data()->size() - 1;

        for (size_t i = 1; i < i_max; i += 2)
            for (size_t j = 1; j < j_max; j += 2) {
                if (map_[i][j] != id_empty_) continue;
                if ((i >= 2 && map_[i - 2][j] == id_wall_) || (j >= 2 && map_[i][j - 2] == id_wall_)) {
                    select_x[ii] = i;
                    select_y[ii] = j;
                    ++ii;
                }
                else if ((j == map_.data()->size() - 2) && (i == map_.size() - 2)) break;
                else if ((i + 2 < map_.size() && map_[i + 2][j] == id_wall_) || (j + 2 < map_.data()->size() && map_[i][j + 2] == id_wall_)) {
                    select_x[ii] = i;
                    select_y[ii] = j;
                    ++ii;
                }
            }
        return ii;
    }
    void mazeMake(vvsize_t& map_, const size_t id_wall_, const size_t id_empty_)
    {
        if (map_.size() <= 2 || map_.data()->size() <= 2) return;
        if ((map_.size() & 1) == 0 || (map_.data()->size() & 1) == 0) return;

        map_[1][1] = id_empty_;

        size_t a, ii;
        std::unique_ptr<size_t[]> select_x(new size_t[map_.size() * map_.data()->size()]);
        std::unique_ptr<size_t[]> select_y(new size_t[map_.size() * map_.data()->size()]);

        //���W��I��
        while (true)
        {
            ii = mazeMakeLoop(map_, id_wall_, id_empty_, select_x, select_y);
            if (ii == 0) break;
            srand((unsigned int)time(nullptr));
            a = size_t(rand()) % ii;
            mazeDig(map_, select_x[a], select_y[a], id_wall_, id_empty_);
        }
        return;
    }
    //���H����
    int createMaze(const size_t x_, const size_t y_, const size_t id_empty_, const size_t id_wall_, const size_t id_root_) {
        if (x_ <= 2 || y_ <= 2) return 1;
        if ((x_ & 1) == 0 || (y_ & 1) == 0) return 2;

        //���H�}�b�v(�S�Ă̈ʒu��ǂɂ���)
        vvsize_t map_{ vvsize_t(y_, vsize_t(x_, id_wall_)) };
        //���H�𐶐�
        mazeMake(map_, id_wall_, id_empty_);
        //�o�H�T��
        mazeRoot(map_, id_empty_, id_root_);
        //�o��
        mazeOutput(map_, id_wall_, id_empty_);
        return 0;
    }
    //���H�}�b�v��Ԃ�
    const vvsize_t createMazeMap(const size_t x_, const size_t y_, const size_t id_empty_, const size_t id_wall_, const size_t id_root_) {
        //���H�}�b�v(�S�Ă̈ʒu��ǂɂ���)
        static thread_local vvsize_t map_;
        map_.clear();
        map_ = vvsize_t{ vvsize_t(y_, vsize_t(x_, id_wall_)) };
        //���H�𐶐�
        mazeMake(map_, id_wall_, id_empty_);
        //�o�H�T��
        mazeRoot(map_, id_empty_, id_root_);
        return map_;
    }

    // CSV�`���Ŗ��H���o��
    void mazeOutputCSV(const vvsize_t& map_, const size_t id_wall_, const size_t id_empty_, const std::string& filename)
    {
        if (!mapCheck(map_)) return;

        std::ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            std::cerr << "Error: Unable to open the file for writing." << std::endl;
            return;
        }

        const size_t i_max = map_.size();
        const size_t j_max = map_.data()->size();

        for (size_t i = 0; i < i_max; ++i) {
            for (size_t j = 0; j < j_max; ++j) {
                if (map_[i][j] == id_empty_) outputFile << "1";
                else if (map_[i][j] == id_wall_) outputFile << "0";
                else outputFile << "1";

                if (j < j_max - 1) outputFile << ",";  // �t�B�[���h�̋�؂�
            }
            outputFile << std::endl;
        }

        outputFile.close();
        std::cout << "CSV file saved successfully: " << filename << std::endl;
    }


}
//���H�̉���
constexpr size_t size_x = 51;
//���H�̏c��
constexpr size_t size_y = 51;

//���H�ɐݒu���镨�̂�ID
enum :size_t {
    id_empty_,//�ʘH
    id_wall_,//��
    id_root_,//�S�[���܂ł̓�
};

int SaveMap()
{
    // ���H����
    const std::string csvFilename = "maze_output.csv";
    maze::createMaze(size_x, size_y, id_empty_, id_wall_, id_root_);
    const maze::vvsize_t mazeMap = maze::createMazeMap(size_x, size_y, id_empty_, id_wall_, id_root_);
    maze::mazeOutputCSV(mazeMap, id_wall_, id_empty_, csvFilename);

    //���H����
    return maze::createMaze(size_x, size_y, id_empty_, id_wall_, id_root_);
}

void MakeMaze::Release()
{
}
