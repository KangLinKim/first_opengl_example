#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

int main(int argc, const char** argv) {
    SPDLOG_INFO("Start program");

    // glfw 라이브러리 초기화, 실패하면 에러 출력후 종료
    SPDLOG_INFO("Initialize glfw");
    if (!glfwInit()) {                                                      // glfwInit이라는 함수를 초기화. 초기화에 실패할경우 0나 false가 출력될텐데 !는 not이라는 의미이므로 if이하는 'glfwInit이 실패한다면'이라는 의미를 갖는다
        const char* description = nullptr;                                  // |
        glfwGetError(&description);                                         // |glfwGetError라는 함수를 이용해 윗줄에서 char형식으로 사유를 얻어와 아랫줄로 이동해 error와 사유메시지를 출력한다는 뜻  
        SPDLOG_ERROR("failed to initialize glfw: {}", description);         // |
        return -1;
    }

    // glfw 윈도우 생성, 실패하면 에러 출력후 종료
    SPDLOG_INFO("Create glfw window");
    auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr); // auto라는 타입은 변수의 타입을 자동으로 지정하는 키워드 개꿀기능임
    if (!window) {                                                                              // |window생성에 실패했을경우
        SPDLOG_ERROR("failed to create glfw window");                                           // |이 메시지를 출력한다
        glfwTerminate();                                                                        // |
        return -1;
    }

    // glfw 루프 실행, 윈도우 close 버튼을 누르면 정상 종료
    SPDLOG_INFO("Start main loop");
    while (!glfwWindowShouldClose(window)) {                                // 윈도우창을 닫아야하는지 물어보는 문장        반복함수를 사용했음
        glfwPollEvents();                                                   // window와 관련된 이벤트들을 수집하는 함수     굳이 포함되는 이유는 위의 줄 하나만 있으면 너무 빨리 물어봐서 컴퓨터의 기능이 저하될 수 있다는듯
    }

    glfwTerminate();
    return 0;                                                               //실행이 완료되면 마지막에 'code 0'라는 메시지도 출력되는데 0을 return하라는 명령어가 실행됐다는걸 알리는것임. 문제가 발생했을 때 error code """"출력되는걸 생각해보면 될듯
}