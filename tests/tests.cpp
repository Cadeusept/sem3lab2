//Copyright 2021 Matthew abobus1488822@yandex.ru

#include <gtest/gtest.h>

#include <investigation.hpp>
#include <stdexcept>

TEST(Equality,Kbytes_to_elems){
  EXPECT_EQ(kbytes_to_elems(1),256);
}

TEST(Equality, Straight_exp){
  EXPECT_EQ(straight_experiment(0),0);
}

TEST(Equality, Reverse_exp){
  EXPECT_EQ(reverse_experiment(0),0);
}

TEST(Equality, Random_exp){
  EXPECT_EQ(random_experiment(0),0);
}

TEST(Equality, Straight_inv){
  std::ofstream fout;
  fout.open(TESTFILE_DIR"test_outpt.md", std::ofstream::out);

  straight_investigation(new int[0], fout);

  fout.close();
  std::ifstream file1(TESTFILE_DIR"test_outpt.md");
  std::string test_outpt((std::istreambuf_iterator<char>(file1)),
                      std::istreambuf_iterator<char>());

  std::ifstream file2(TESTFILE_DIR"test1.md");
  std::string eq_outpt((std::istreambuf_iterator<char>(file2)),
                      std::istreambuf_iterator<char>());

  EXPECT_EQ(test_outpt, eq_outpt);
}

TEST(Equality, Reverse_inv){
  std::ofstream fout;
  fout.open(TESTFILE_DIR"test_outpt.md", std::ofstream::out);

  reverse_investigation(new int[0], fout);

  fout.close();
  std::ifstream file1(TESTFILE_DIR"test_outpt.md");
  std::string test_outpt((std::istreambuf_iterator<char>(file1)),
                      std::istreambuf_iterator<char>());

  std::ifstream file2(TESTFILE_DIR"test2.md");
  std::string eq_outpt((std::istreambuf_iterator<char>(file2)),
                      std::istreambuf_iterator<char>());

  EXPECT_EQ(test_outpt, eq_outpt);
}

TEST(Equality, Random_inv){
  std::ofstream fout;
  fout.open(TESTFILE_DIR"test_outpt.md", std::ofstream::out);

  random_investigation(new int[0], fout);

  fout.close();
  std::ifstream file1(TESTFILE_DIR"test_outpt.md");
  std::string test_outpt((std::istreambuf_iterator<char>(file1)),
                      std::istreambuf_iterator<char>());

  std::ifstream file2(TESTFILE_DIR"test3.md");
  std::string eq_outpt((std::istreambuf_iterator<char>(file2)),
                      std::istreambuf_iterator<char>());

  EXPECT_EQ(test_outpt, eq_outpt);
}

TEST(Equality, Cpu_test){
  std::ofstream fout;
  fout.open(TESTFILE_DIR"test_outpt.md", std::ofstream::out);

  test_cpu(new int[0], fout);

  fout.close();
  std::ifstream file1(TESTFILE_DIR"test_outpt.md");
  std::string test_outpt((std::istreambuf_iterator<char>(file1)),
                      std::istreambuf_iterator<char>());

  std::ifstream file2(TESTFILE_DIR"test4.md");
  std::string eq_outpt((std::istreambuf_iterator<char>(file2)),
                      std::istreambuf_iterator<char>());

  EXPECT_EQ(test_outpt, eq_outpt);
}

TEST(Equality,Print_hdr){
  std::ofstream fout;
  fout.open(TESTFILE_DIR"test_outpt.md", std::ofstream::out);

  print_header("random",fout);

  fout.close();
  std::ifstream file1(TESTFILE_DIR"test_outpt.md");
  std::string test_outpt((std::istreambuf_iterator<char>(file1)),
                      std::istreambuf_iterator<char>());

  std::ifstream file2(TESTFILE_DIR"test5.md");
  std::string eq_outpt((std::istreambuf_iterator<char>(file2)),
                      std::istreambuf_iterator<char>());

  EXPECT_EQ(test_outpt, eq_outpt);
}

TEST(Equality, Print_exp){
  std::ofstream fout;
  fout.open(TESTFILE_DIR"test_outpt.md", std::ofstream::out);

  print_experiment_data(3,5,10,fout);

  fout.close();
  std::ifstream file1(TESTFILE_DIR"test_outpt.md");
  std::string test_outpt((std::istreambuf_iterator<char>(file1)),
                      std::istreambuf_iterator<char>());

  std::ifstream file2(TESTFILE_DIR"test6.md");
  std::string eq_outpt((std::istreambuf_iterator<char>(file2)),
                      std::istreambuf_iterator<char>());

  EXPECT_EQ(test_outpt, eq_outpt);
}

TEST(Equality, Print_ftr){
  std::ofstream fout;
  fout.open(TESTFILE_DIR"test_outpt.md", std::ofstream::out);

  print_footer(fout);

  fout.close();
  std::ifstream file1(TESTFILE_DIR"test_outpt.md");
  std::string test_outpt((std::istreambuf_iterator<char>(file1)),
                      std::istreambuf_iterator<char>());

  std::ifstream file2(TESTFILE_DIR"test7.md");
  std::string eq_outpt((std::istreambuf_iterator<char>(file2)),
                      std::istreambuf_iterator<char>());

  EXPECT_EQ(test_outpt, eq_outpt);
}
