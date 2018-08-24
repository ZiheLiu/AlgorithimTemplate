#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

/**
 * https://www.hackerrank.com/challenges/cloudy-day/problem
 */

/**
 * 题意
 *  在x轴上，有若干个城市，城市有它的x轴坐标、人口数。
 *  在x轴上，有若干个云，云有它的x轴坐标、范围range，它能覆盖的范围是[x - range, x + range]
 *  现在去掉一块云，求不被云遮住的城市的人口数目的最大值。
 */

/**
 * 解法
 *  把城市、云的左端点、云的右端点都放进一个数组，并且按照x轴坐标排序(node_list)。
 *  在x轴坐标相同时，云的左端点 < 城市 < 云的右端点。这样可以保证每个点，先加入云，再计算城市的覆盖情况，再删除云。
 *  使用一个set(alive_clouds)记录当前被加入的云。
 *  遍历node_list，
 *      - 如果node是云的左端点，把云加入alive_clouds。
 *      - 如果node是云的右端点，把云从alive_clouds中删除。
 *     -  如果node是城市，查看alive_clouds的size，
 *          - 如果size为0，说明没有云覆盖，把这个城市的人口数目加入sum值。
 *          - 如果size为1，把这个城市的人口数目加入alive_clouds[0]的云。
 *          - 如果size为2，继续。
 */

typedef long long ll;

const ll kTownsCount = 2e5 + 2;
const ll kCloudsCount = 1e5 + 2;

struct Node {
    ll pos;
    ll type; // 1: cloud_start, 2: town, 3: cloud_end
    ll index;

    bool operator < (const Node& node) const {
        return (this->pos < node.pos) || (this->pos == node.pos && this->type < node.type);
    }
} nodes[kTownsCount + kCloudsCount * 2];

ll town_populations[kTownsCount];
ll town_locations[kTownsCount];
ll cloud_locations[kCloudsCount];
ll cloud_ranges[kCloudsCount];

ll cloud_populations[kCloudsCount];

ll towns_count, clouds_count;
ll tmp;


void input() {
    scanf("%lld", &towns_count);
    for (long long i = 0; i < towns_count; i++) {
        scanf("%lld", &tmp);
        town_populations[i] = tmp;
    }
    for (long long i = 0; i < towns_count; i++) {
        scanf("%lld", &tmp);
        town_locations[i] = tmp;
    }
    scanf("%lld", &clouds_count);
    for (long long i = 0; i < clouds_count; i++) {
        scanf("%lld", &tmp);
        cloud_locations[i] = tmp;
    }
    for (long long i = 0; i < clouds_count; i++) {
        scanf("%lld", &tmp);
        cloud_ranges[i] = tmp;
    }
}



ll maximum_people() {
    ll pos = 0;
    for (ll i = 0; i < towns_count; i++) {
        nodes[pos].type = 2;
        nodes[pos].index = i;
        nodes[pos].pos = town_locations[i];
        pos++;
    }
    for (ll i = 0; i < clouds_count; i++) {
        nodes[pos].type = 1;
        nodes[pos].index = i;
        nodes[pos].pos = cloud_locations[i] - cloud_ranges[i];
        pos++;

        nodes[pos].type = 3;
        nodes[pos].index = i;
        nodes[pos].pos = cloud_locations[i] + cloud_ranges[i];
        pos++;
    }

    sort(nodes, nodes + pos);

    unordered_set<ll> alive_clouds;
    ll population_sum = 0;

    for (Node &node : nodes) {
        if (node.type == 2) {
            if (alive_clouds.empty()) {
                population_sum += town_populations[node.index];
            } else if (alive_clouds.size() == 1) {
                cloud_populations[*(alive_clouds.begin())] += town_populations[node.index];
            }
        } else if (node.type == 1) {
            alive_clouds.insert(node.index);
        } else {
            alive_clouds.erase(node.index);
        }
    }

    ll max_cloud_population = 0;
    for (ll i = 0; i < clouds_count; i++) {
        max_cloud_population = max(max_cloud_population, cloud_populations[i]);
    }

    return max_cloud_population + population_sum;
}

int main() {
    // freopen("../input", "r", stdin);

    input();
    cout << maximum_people();

    return 0;
}
